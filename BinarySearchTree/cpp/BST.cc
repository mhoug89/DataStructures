#include <iostream>
#include "BST.h"

TreeNode* BST::FindNode(TreeNode *node, int val) {
    if (node == NULL) {
        return NULL;
    } else if (val == node->data) {
        return node;
    } else if (val < node->data) {
        if (node->lc == NULL) {
            return NULL;
        }
        return FindNode(node->lc, val);
    } else {
        if (node->rc == NULL) {
            return NULL;
        }
        return FindNode(node->rc, val);
    }
}

void BST::InsertTreeNode(TreeNode *root, TreeNode *node) {
    if (node->data > root->data) {
        if (root->rc == NULL) {
            root->rc = node;
        } else {
            InsertTreeNode(root->rc, node);
        }
    } else if (node->data < root->data) {
        if (root->lc == NULL) {
            root->lc = node;
        } else {
            InsertTreeNode(root->lc, node);
        }
    }
    // else return; // no duplicate keys allowed
}

void BST::TraversePreOrderRec(TreeNode *node) {
    if (node == NULL) {
        return;
    }
    std::cout << node->data << " ";
    TraversePreOrderRec(node->lc);
    TraversePreOrderRec(node->rc);
}

void BST::TraverseInOrderRec(TreeNode *node) {
    if (node == NULL) {
        return;
    }
    TraverseInOrderRec(node->lc);
    std::cout << node->data << " ";
    TraverseInOrderRec(node->rc);
}

void BST::TraversePostOrderRec(TreeNode *node) {
    if (node == NULL) {
        return;
    }
    TraversePostOrderRec(node->lc);
    TraversePostOrderRec(node->rc);
    std::cout << node->data << " ";
}

void BST::InsertTreeNode(TreeNode *node) {
    if (root == NULL) {
        root = node;
    } else {
        InsertTreeNode(root, node);
    }
}

void BST::TraversePreOrder() {
    std::cout << "Pre order traversal of the tree: ";
    TraversePreOrderRec(root);
    std::cout << "\n\n";
}

void BST::TraverseInOrder() {
    std::cout << "In order traversal of the tree: ";
    TraverseInOrderRec(root);
    std::cout << "\n\n";
}

void BST::TraversePostOrder() {
    std::cout << "Post order traversal of the tree: ";
    TraversePostOrderRec(root);
    std::cout << "\n\n";
}

TreeNode* BST::FindParent(int val) {
    TreeNode *node = root;
    if (root->data == val) {
        return NULL;
    }
    while (node != NULL) {
        if (val < node->data) {
            if (node->lc != NULL && node->lc->data == val) {
                return node;
            } else {
                node = node->lc;
            }
        } else {
            if (node->rc != NULL && node->rc->data == val) {
                return node;
            } else {
                node = node->rc;
            }
        }
    }
    return NULL;
}

TreeNode* BST::FindParent(TreeNode *node) {
    TreeNode *cur = root;
    if (cur == node) {
        return NULL;
    }
    while (cur != NULL && cur->lc != node && cur->rc != node) {
        if (node->data < cur->data) {
            cur = cur->lc;
        } else {
            cur = cur->rc;
        }
    }
    return cur; // could be NULL
}

TreeNode* BST::FindNode(int val) {
    return FindNode(root, val);
}

void BST::DeleteTreeNode(int val) {
    TreeNode *node = FindNode(val);
    DeleteTreeNode(node);
}

void BST::DeleteTreeNode(TreeNode *node) {
    if (node == NULL) {
        return;
    }

    TreeNode *par = FindParent(node);
    // if it has no children, you can just delete it and change its
    // parent's reference to it to NULL
    if (node->rc == NULL && node->lc == NULL) {
        // if it's the tree root
        if (par == NULL) {
            delete this->root;
            this->root = NULL;
        } else {
            if (node == par->lc) {
                par->lc = NULL;
                delete node;
            } else {    // par->rc
                par->rc = NULL;
                delete node;
            }
        }
    } else if (node->lc != NULL && node->rc != NULL) {
        // two children - find the left-most child, the min, of the right
        // sub-tree of node, and replace node's value with min's value,
        // followed by deleting min.
        TreeNode *minNode = FindMin(node->rc);
        node->data = minNode->data;
        DeleteTreeNode(minNode);
    } else { // one child
        // move left child up to node's place and delete node
        if (node->lc != NULL) {
            // if it's the tree root
            if (par == NULL) {
                TreeNode* temp = root;
                root = node->lc;
                delete temp;
            } else {
                if (par->lc == node) {
                    par->lc == node->lc;
                    delete node;
                } else {
                    par->rc == node->lc;
                    delete node;
                }
            }
        } else { // move right child up to node's place and delete node
            // if it's the tree root
            if (par == NULL) {
                TreeNode* temp = root;
                root = node->rc;
                delete temp;
            } else {
                if (par->lc == node) {
                    par->lc == node->rc;
                    delete node;
                } else {
                    par->rc == node->rc;
                    delete node;
                }
            }
        }
    }
}

TreeNode* BST::FindMin(TreeNode *node) {
    while (node->lc != NULL) {
        node = node->lc;
    }
    return node;
}
