class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if ( !root)
            return nullptr;
        if ( key < root->val) {
            root->left = deleteNode(root->left, key);
        }else if ( key > root->val) {
            root->right = deleteNode(root->right, key);
        }else {
            if ( !root->left && !root->right ) {
                delete root;
                return nullptr;
            }else if ( root->left == nullptr || root->right == nullptr){
                // if only one node is present...
                auto tmp = ( root->left) ? root->left : root->right;
                delete root;
                return tmp;

            }else if ( root->left && root->right) {
                auto curr = root->right;
                while ( curr && curr->left) {
                    curr = curr->left;
                };
                root->val = curr->val;
                root->right = deleteNode(root->right, curr->val); 

            }
        }
        return root;


    }
};
