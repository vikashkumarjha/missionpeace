class Solution {
public:
    class TreeNode {
    public:
        TreeNode* left;
        TreeNode* right;
        TreeNode () {left = NULL; right = NULL;};
    };
    TreeNode* buildTree(vector<int>& nums) {
        TreeNode* root = new TreeNode(), *curr;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            curr = root;
            for (int j = 31; j >= 0; j--) {
                int bit = ((num >> j) & 1);
                
                if ( bit == 0) {
                    if ( !curr->left) {
                        curr->left = new TreeNode();
                    }
                    curr = curr->left;
                }else {
                    if ( !curr->right) {
                        curr->right = new TreeNode();
                    }
                    curr = curr->right;
                }
                
            }
        }
        return root;
    }
    
    int helper(TreeNode* curr, int num) {
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = ((num >> i) & 1);
            
            if ( bit == 0) {
                if ( curr->right) {
                    res += pow(2, i);
                    curr = curr->right;
                }else {
                    curr = curr->left;
                }
            }else {
                if (curr->left) {
                    res += pow(2,i); 
                    curr = curr->left;
                }else {
                    curr = curr->right;
                }
                
            }
          
        }
        return res;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        TreeNode* root = buildTree(nums);
        
        for (auto i : nums) {
            res = max(res, helper(root, i));
        }
        
        return res;
    }
};