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
private:
   
    bool helper(TreeNode* root, int & size, int & minVal, int & maxVal){
        if (!root) return true;
       
        int sizeL = 0, sizeR = 0;
        int minValL = INT_MAX, maxValL = INT_MIN;
        int minValR = INT_MAX, maxValR = INT_MAX;
           
        bool  x = helper(root->left,  sizeL, minValL, maxValL);
        bool  y = helper(root->right, sizeR, minValR, maxValR);
       
        if ((x && y) &&
           ((root->left  == nullptr || root->val > maxValL)) &&
           ((root->right == nullptr || root->val < minValR))){
           
            size = sizeL + sizeR + 1;
           
            minVal = root->left  ? minValL : root->val;
            maxVal = root->right ? maxValR : root->val;

            return true;
        }
       
        size = max(sizeL, sizeR);
        return false;        
    }
   
public:
   
    int largestBSTSubtree(TreeNode* root) {
        if (!root) return 0;
       
        int minval = INT_MAX;
        int maxval = INT_MIN;
        int globalMaxSize = 0;
       
        helper(root, globalMaxSize, minval, maxval);
       
        return globalMaxSize;  
    }
};