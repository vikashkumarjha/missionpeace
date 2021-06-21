class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if ( !root) return res;
        
        map<int,vector<int>> m;
        queue<pair<int,TreeNode*>> q;
        q.push({0,root});
        
        while ( !q.empty())
        {
            auto qsize = q.size();
            while ( qsize--)
            {
                auto x = q.front(); q.pop();
                m[x.first].push_back((x.second)->val);
                if ( x.second->left) {
                    q.push({x.first - 1, x.second->left});    
                }
                if ( x.second->right) {
                    q.push({x.first + 1, x.second->right});
                }
                
            }
            
        }
        for ( auto row : m) {
            res.push_back(row.second);   
        }
        
        return res;
        
    }
};