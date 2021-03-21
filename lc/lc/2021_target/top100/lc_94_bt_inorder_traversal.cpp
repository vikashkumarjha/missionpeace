//write for the inorder...
#include "../header.hpp"


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if ( !root) return result;

        stack<TreeNode*> st;
        TreeNode *curr = root;

        while ( curr || !st.empty()) {
            while ( curr) {
                st.push(curr);
                curr = curr->left;
            }
            if ( st.empty()) break;

            curr = st.top(); st.pop();
            result.push_back(curr->val);
            curr = curr->right;
        }
        return result;
    }
};


int main()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution s;
    auto r = s.inorderTraversal(root);
    for (auto x : r) {
        cout << x << " ";
    }
    return 0;
}