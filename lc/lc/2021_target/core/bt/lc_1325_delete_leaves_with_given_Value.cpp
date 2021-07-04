
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (!root) return nullptr;

        root->left  = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        // Here we are Pruning Leafs whose  Value is 0
        if ((root->left == nullptr) && (root->right == nullptr) && root->val == target) 
            return nullptr;
        else
            return root;
    }
};
