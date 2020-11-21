/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };


 Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
 */
class Solution {
public:
    TreeNode* _flatten(TreeNode* root){
        if(root->right == NULL && root->left == NULL)
            return root;
        TreeNode *tail;
        if(root->left != NULL){
            tail = _flatten(root->left);
            tail->right = root->right;
        }
        if(root->right != NULL){
            tail = _flatten(root->right);
        }
        if(root->left != NULL)
            root->right = root->left;
        root->left = NULL;
        return tail;
    }
    void flatten(TreeNode* root) {
        if(root == NULL)
            return;
        _flatten(root);
    }
};