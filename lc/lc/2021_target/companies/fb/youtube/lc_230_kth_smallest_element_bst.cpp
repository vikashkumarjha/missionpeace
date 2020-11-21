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


class Solution { // inorder traversal
public:
    int kthSmallest(TreeNode* root, int k) {
        kthSmallestDFS(root, k);
        return ret;
    }
    void kthSmallestDFS(TreeNode* root, int &k) {
        if(!root) return;
        kthSmallestDFS(root->left, k);
        if(--k == 0) ret = root->val;
        kthSmallestDFS(root->right, k);
    }
private:
    int ret = 0;
};
