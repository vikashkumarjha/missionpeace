Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 


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
    void flatten(TreeNode* root) {

        if(root != NULL)
        {
            dfs(root);
        }
    }

    TreeNode* dfs(TreeNode* node)
    {
        if(node->left == NULL && node->right == NULL)
        {
            return node;
        }

        if(node->left != NULL)
        {
            TreeNode* newNode = dfs(node->left);
            std::cout << "\n node val:" << newNode->val << node->val;
            newNode->right = node->right;
            node->right = node->left;
            node->left = NULL;
            node = newNode;
        }
        if(node->right != NULL)
        {
            return dfs(node->right);
        }

        return node;
    }
};