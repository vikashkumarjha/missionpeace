class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
            vector<int> lefts; // left most nodes at each level;
            int maxwidth = 0;
            dfs(root, 1, 0, lefts, maxwidth);
            return maxwidth;
        }
private:
    void dfs(TreeNode* node, int id, int depth, vector<int>& lefts, int& maxwidth) {
            if (!node) return;
            if (depth >= lefts.size()) lefts.push_back(id);  // add left most node
            maxwidth = max(maxwidth, id + 1 - lefts[depth]);
            dfs(node->left, id * 2, depth + 1, lefts, maxwidth);
            dfs(node->right, id * 2 + 1, depth + 1, lefts, maxwidth);
        }
};


class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        if (root == nullptr) return 0;
        queue<pair<TreeNode*, long>> q;
        q.push(make_pair(root, 0));
        int res = 0;
        while (!q.empty())
        {
            int size = q.size();
            int begin, end;
            for (int i = 0; i < size; i++)
            {
                auto cur = q.front();
                q.pop();
                auto node = cur.first;

                if (i == 0)
                {
                    begin = cur.second;
                }
                if (i == size-1)
                {
                    end = cur.second;
                }
                if (node->left != nullptr)
                {
                    q.push(make_pair(node->left, cur.second * 2));
                }
                if (node->right != nullptr)
                {
                    q.push(make_pair(node->right, cur.second * 2+1));
                }
            }
            res = max (res, end-begin +1);
        }
        return res;


    }
};
