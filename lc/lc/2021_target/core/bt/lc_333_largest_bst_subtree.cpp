/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

Given the root of a binary tree, find the largest subtree, which is also a Binary Search Tree (BST), where the largest means subtree has the largest number of nodes.

A Binary Search Tree (BST) is a tree in which all the nodes follow the below-mentioned properties:

The left subtree values are less than the value of their parent (root) node's value.
The right subtree values are greater than the value of their parent (root) node's value.
Note: A subtree must include all of its descendants.


class Solution {
private:
    class myclass{
    public:
        bool isBST;
        int size;
        int min;
        int max;
        myclass(bool isBST_, int size_, int min_, int max_): isBST(isBST_), size(size_),
        min(min_), max(max_) {

        }
    };

    myclass helper(int &result, TreeNode* root) {
        if (!root) {
            return myclass(true, 0, INT_MAX, INT_MIN);
        } 

        myclass left = helper(result, root->left);
        myclass right = helper(result, root->right);

        bool isBST = left.isBST && right.isBST && (!root->left || left.max < root->val) 
            && (!root->right || right.min > root->val);
        int mymin = min(left.min, min(root->val, right.min));
        int mymax = max(left.max, max(root->val, right.max));
        int size = 1 + left.size + right.size;

        if (isBST) {
            result = max(result, size);
        }
        return myclass(isBST, size, mymin, mymax);
    }
public:
    int largestBSTSubtree(TreeNode* root) {
        int result = 0;
        myclass mc = helper(result, root);
        return result;
    }
};
