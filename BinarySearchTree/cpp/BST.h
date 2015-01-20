#ifndef __MY_BST_H__
#define __MY_BST_H__

class TreeNode {
  public:
    TreeNode *lc, *rc;
    int data;

    TreeNode() : lc(NULL), rc(NULL) { }
    TreeNode(const int& data) : data(data), lc(NULL), rc(NULL) { }
    static int get_data(TreeNode *node) {
        return (node == NULL) ? -99999999 : node->data;
    }
};

class BST {
  private:
    TreeNode *root;

    TreeNode* FindNode(TreeNode*, int);
    void InsertTreeNode(TreeNode*, TreeNode*);
    void TraverseInOrderRec(TreeNode*);
    void TraversePostOrderRec(TreeNode*);
    void TraversePreOrderRec(TreeNode*);

  public:
    BST() : root(NULL) { }
    BST(TreeNode *root) : root(root) { }

    void DeleteTreeNode(int val);
    void DeleteTreeNode(TreeNode *node);
    TreeNode* FindMin(TreeNode *node);
    TreeNode* FindNode(int val);
    TreeNode* FindParent(int val);
    TreeNode* FindParent(TreeNode *node);
    void InsertTreeNode(TreeNode *node);
    void TraverseInOrder();
    void TraversePreOrder();
    void TraversePostOrder();
};

#endif
