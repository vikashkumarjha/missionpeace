class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty())
        {
            auto x = st.top(); st.pop();
            res.push_back(x->val);
            if ( x->right) {
                st.push(x->right);
            }
            if (x->left) {
                st.push(x->left);
            }
        }

        return res;
    }
};
