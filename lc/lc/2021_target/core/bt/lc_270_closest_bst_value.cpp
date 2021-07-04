class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        if ( !root) return -1;
        int closestVal = root->val;
        while ( root ){
            if ( std::abs(root->val - target ) < std::abs(closestVal - target)){
                closestVal = root->val;
            }
            root =  ( root->val > target ) ? root->left : root->right;
        }
        return closestVal;

    }
};
