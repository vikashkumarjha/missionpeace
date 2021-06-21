class Solution {
private:
    int R;
    int C;
    
    vector<vector<int>> DIRS = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    
    
    
public:
    int dfs(vector<vector<int>> &m, int r, int c, vector<vector<int>> &cache) {
        if (cache[r][c]) {
            return cache[r][c];
        }
        
        int maxPath = 0;
        
        for ( auto d : DIRS) {
            int x = r + d[0];
            int y = c + d[1];
            if ( x >= 0 && x < R && y >= 0 && y < R && m[x][y] > m[r][c]) {
                int val = dfs(m, x, y, cache) + 1;
                maxPath = max(val, maxPath);
            }
            
        }
        cache[r][c] = maxPath;
        return cache[r][c];
        
    }
    
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if ( matrix.empty()) return 0;
        R = matrix.size();
        C = matrix[0].size();
        int ans = 0;
        
        vector<vector<int>> cache(R, vector<int>(C,0));
        
        
        for ( int i = 0; i < R; i++)
        {
            for ( int j = 0; j < C; j++) {
                ans = max(ans, dfs(matrix, i, j, cache));
            }
        }
        
        return ans;
        
    }
};