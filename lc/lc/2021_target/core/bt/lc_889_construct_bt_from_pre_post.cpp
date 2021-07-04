class Solution {
public:
    TreeNode *helper(vector<int>& pre, vector<int>& post, int &preStart, int postStart, int postEnd) {
        if ( postStart > postEnd) return nullptr;

        TreeNode *root = new TreeNode(pre[preStart]);
        preStart++;

        if ( postStart == postEnd) return root;
        int idx = postStart;
        for ( int k = postStart; k <= postEnd; k++) {
            if ( post[k] == pre[preStart]){
                idx = k;
                break;
            }
        }

        root->left = helper(pre, post, preStart, postStart, idx);
        root->right = helper(pre, post, preStart, idx + 1, postEnd - 1);

        return root;

    }


    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if ( pre.size() != post.size()) return nullptr;

        int preStart = 0;
        int preEnd = pre.size() - 1;
        int postStart = 0;
        int postEnd = post.size() - 1;


        TreeNode *root = helper(pre, post, preStart, postStart, postEnd);

        return root;




    }
};
