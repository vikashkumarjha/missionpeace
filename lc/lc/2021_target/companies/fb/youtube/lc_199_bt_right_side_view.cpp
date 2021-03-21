
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
public:
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> result;
        if (!root){
            return result;
        }
        std::queue<TreeNode*> q;
        q.push(root);

        while ( !q.empty()){
            size_t qsize = q.size();
            for ( size_t i = 0; i < qsize; i++ ){
                TreeNode *curr = q.front();
                q.pop();
                if ( i == qsize - 1){
                    result.push_back(curr->val);
                }

                if ( curr->left){
                    q.push(curr->left);
                }

                if ( curr->right){
                    q.push(curr->right);
                }
            }
        }
        return result;
    }
};


class Solution {

private:
    void dfs(TreeNode* root, std::vector<int> &result, int level){

        if ( !root)
            return;
        if ( result.size() == level){
            result.push_back(root->val);
        }
        dfs(root->right, result, level + 1);
        dfs(root->left, result, level + 1);

    }
public:
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> result;
        if ( !root )
            return result;
        dfs(root, result, 0);
        return result;
    }
};
