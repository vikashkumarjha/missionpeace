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
private:
    map<int, map<int, set<int>>> m;
    
public:
    void treeDFS(TreeNode * root, int x, int y){
        if (!root)
            return;
    
        m[x][y].insert(root->val);

        treeDFS(root->left,  x - 1, y + 1);
        treeDFS(root->right, x + 1, y + 1);   
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        treeDFS(root, 0, 0);
        
        vector<vector<int>> result;
        
        for (const auto & iter1 : m){
            vector<int> tmp;
            for (const auto & iter2 :iter1.second)
                for (const auto & iter3 : iter2.second)
                    tmp.push_back(iter3);
            
            result.push_back(tmp);
        }
        
        return result;
        
    }
};