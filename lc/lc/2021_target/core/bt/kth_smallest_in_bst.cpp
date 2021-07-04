class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
         stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()&&k){
            TreeNode *cur=stk.top();
            while (cur->left){
                stk.push(cur->left);
                cur=cur->left;
            }
            do{
                cur=stk.top();
                stk.pop();
                k--;
                if (k==0) return cur->val;
            } while(!cur->right);
            stk.push(cur->right);
        }
        
    }
};
