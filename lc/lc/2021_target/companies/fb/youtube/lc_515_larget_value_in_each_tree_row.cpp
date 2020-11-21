class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root){
            return vector<int>{};
        }
        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);

        while ( !q.empty()){
            size_t currQSize = q.size();
            int candidate = INT_MIN;
            while ( currQSize--){
                auto curr = q.front();
                q.pop();
                candidate = max(candidate, curr->val);
                if ( curr->left){
                    q.push(curr->left);
                }
                if (curr->right){
                    q.push(curr->right);
                }
            }
            result.push_back(candidate);

        }
        return result;

    }
};
