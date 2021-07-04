Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int isBtHeightBalancedHelper(TreeNode* root, bool &value)
    {
        if ( !root) return 0;
        int lDepth = isBtHeightBalancedHelper(root->left,value);
        int rDepth = isBtHeightBalancedHelper(root->right,value);

        if ( std::abs(lDepth - rDepth) > 1){
            value = false;
        }
        return std::max(lDepth,rDepth) + 1;

    }

    bool isBalanced(TreeNode* root){

        bool value = true;
        if ( !root) return value;

        isBtHeightBalancedHelper(root, value);


        return value;


    }

};
