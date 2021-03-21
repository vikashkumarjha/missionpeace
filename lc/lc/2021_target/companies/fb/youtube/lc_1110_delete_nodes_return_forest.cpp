/*
 * Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest.  You may return the result in any order.



Example 1:



Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]


*/


class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        std::set<int> st(to_delete.begin(), to_delete.end());
        vector<TreeNode*> ret;
        dfs(root, st, ret, true);
        return ret;
    }

    void dfs(TreeNode* root, std::set<int>& st, vector<TreeNode*>& ret, bool parentDeleted) {
        if (!root) return;
        bool shouldDelete = st.count(root->val);
        if (parentDeleted && !shouldDelete) {
            ret.push_back(root);
        }

        auto left = root->left, right = root->right;
        if (left && st.count(left->val)) {
            root->left = nullptr;
        }
        if (right && st.count(right->val)) {
            root->right = nullptr;
        }

        dfs(left, st, ret, shouldDelete);
        dfs(right, st, ret, shouldDelete);
    }
};


class Solution {

    vector<TreeNode*> result;
    set<int> to_delete_set;
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (int i : to_delete)
            to_delete_set.insert(i);
        helper(root, result, to_delete_set, true);
        return result;
    }

    TreeNode* helper(TreeNode* node, vector<TreeNode*>& result, set<int>& to_delete_set, bool is_root) {
        if (node == NULL) return NULL;
        bool deleted = to_delete_set.find(node->val) != to_delete_set.end();
        if (is_root && !deleted) result.push_back(node);
        node->left = helper(node->left, result, to_delete_set, deleted);
        node->right =  helper(node->right, result, to_delete_set, deleted);
        return deleted ? NULL : node;
    }
};
