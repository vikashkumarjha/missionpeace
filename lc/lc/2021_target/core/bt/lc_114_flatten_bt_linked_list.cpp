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
