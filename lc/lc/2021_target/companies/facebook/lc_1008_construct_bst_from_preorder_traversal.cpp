/*
Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.
*/

#include <iostream>
#include <vector>

using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

TreeNode *createNode(int x, TreeNode *root) {
    if (!root) {
        return new TreeNode(x);
    }
    if ( x < root->val) {
        root->left = createNode(x, root->left);
    }else {
        root->right = createNode(x, root->right);
    }
    return root;
}



TreeNode* bstFromPreorder(vector<int> &pre) {
    TreeNode *root = nullptr;
    for ( auto x : pre) {
        root = createNode(x, root);
    }
    return root;


}


/*
The trick is to set a range {min .. max} for every node. 
Initialize the range as {INT_MIN .. INT_MAX}. 
The first node will definitely be in range, 
so create a root node. To construct the left subtree, 
set the range as {INT_MIN …root->data}. 
If a value is in the range {INT_MIN .. root->data}, 
the values are part of the left subtree. To construct 
the right subtree, set the range as {root->data..max .. INT_MAX}. 

Give the function a bound the maximum number it will handle.
The left recursion will take the elements smaller than node.val
The right recursion will take the remaining elements smaller than bound

*/

class Solution2 {
public:
     TreeNode* bstFromPreorder(vector<int>& A) {
        int i = 0;
        return build(A, i, INT_MAX);
    }

    TreeNode* build(vector<int>& A, int& i, int bound) {
        if (i == A.size() || A[i] > bound) return nullptr;
        TreeNode* root = new TreeNode(A[i++]);
        root->left = build(A, i, root->val);
        root->right = build(A, i, bound);
        return root;
    }
};

