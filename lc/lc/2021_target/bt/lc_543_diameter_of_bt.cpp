/*
Given a binary tree, you need to compute the length of the diameter
 of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is 
represented by the number of edges between them.

*/

#include<iostream>

using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



class Solution {
private:
    int dfs(TreeNode *root, int &res) {
        if ( !root) return 0;
        int l = dfs(root->left, res);
        int r = dfs(root->right, res);
        res = max( res, l + r);
        return max(l, r) + 1;
    }     
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if ( !root) return 0;
        int result = 0;
        dfs(root, result);
        return result;

    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left= new TreeNode(4);
    root->left->right= new TreeNode(5);


    Solution s;
    int res = s.diameterOfBinaryTree(root);

    cout << "\n Diameter of the BT :" << res ;

    return 0;

}