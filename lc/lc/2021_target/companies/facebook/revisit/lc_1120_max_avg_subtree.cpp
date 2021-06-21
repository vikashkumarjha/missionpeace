class Solution {
public:
    // number, sum
    pair<int, int> helper(TreeNode *root, double &result) {
        if (!root) {
            return {0,0};
        }
        
        auto a = helper(root->left, result);
        auto b = helper(root->right, result);
        
        int totalNodes = a.first + b.first + 1;
        int totalSum = a.second + b.second + root->val;
        
        result = max(result, (1.0  * totalSum) / totalNodes );
        
        return make_pair(totalNodes, totalSum);
        
        
    }
    
    double maximumAverageSubtree(TreeNode* root) {
        double result = 0;
        helper(root, result);
       
        return result;
    }
};