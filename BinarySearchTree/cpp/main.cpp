#include <iostream>
#include "BST.h"

using namespace std;

int main() {
    BST bst(new TreeNode(6));
    bst.InsertTreeNode(new TreeNode(4));
    bst.InsertTreeNode(new TreeNode(8));
    bst.InsertTreeNode(new TreeNode(2));
    bst.InsertTreeNode(new TreeNode(5));
    bst.InsertTreeNode(new TreeNode(7));
    bst.InsertTreeNode(new TreeNode(9));
    bst.TraversePreOrder();
    bst.TraverseInOrder();
    bst.TraversePostOrder();

    cout << "Parent of node with value 6: " << TreeNode::get_data(bst.FindParent(6)) << "\n";
    cout << "Parent of node with value 5: " << TreeNode::get_data(bst.FindParent(5)) << "\n";
    cout << "Parent of node with value 7: " << TreeNode::get_data(bst.FindParent(7)) << "\n";

    //bst.DeleteTreeNode(2);
    //bst.DeleteTreeNode(6);
    bst.DeleteTreeNode(8);
    cout << "\n";
    bst.TraversePreOrder();
    bst.TraverseInOrder();
    bst.TraversePostOrder();

    return 0;
}
