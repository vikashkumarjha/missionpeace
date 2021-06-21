/**
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *        *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *         *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x),
 *         left(left), right(right) {}
 *          * };
 *           */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};

        stack<TreeNode*> st;
        TreeNode *curr = root;
        vector<int> res;

        while (!st.empty() || curr) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top(); st.pop();
            res.push_back(curr->val);

            if ( curr->right) {
                curr = curr->right;
            }else {
                curr = nullptr;
            }

        }

        return res;


    }
};
