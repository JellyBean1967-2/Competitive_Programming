/*
Today HW 1:
Copy da tree from last time get the in order and post order
Today HW 2:
Given the post order and in order of tree
RECONSTRUCT THE TREE.
//   1
//  / \
//  3  2
//  |  | \
//  4  5  6
//    / \  \
//   7   8  9
//  /        \
// 10       11
*/
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    
    root->left->left = new TreeNode(4);
    
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    
    root->right->left->left = new TreeNode(7);
    root->right->left->right = new TreeNode(8);
    root->right->right->right = new TreeNode(9);
    
    root->right->left->left->left = new TreeNode(10);
    root->right->right->right->right = new TreeNode(11);
    
    return root;
}

void in_order(TreeNode* root, vector<int>& result) {
    if (!root) return;
    in_order(root->left, result);
    result.push_back(root->val);
    in_order(root->right, result);
}

void post_order(TreeNode* root, vector<int>& result) {
    if (!root) return;
    post_order(root->left, result);
    post_order(root->right, result);
    result.push_back(root->val);
}

int main() {
    TreeNode* root = buildTree();
    
    // HW 1: Get traversals
    vector<int> inorder_result, postorder_result;
    in_order(root, inorder_result);
    post_order(root, postorder_result);
    
    cout << "In-order: ";
    for (int x : inorder_result) cout << x << " ";
    cout << "\nPost-order: ";
    for (int x : postorder_result) cout << x << " ";
    cout << "\n";
    
    return 0;
}