class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        
        int R = A.size();
        if ( R == 0) return {{}};
        
        int C = A[0].size();
        vector<vector<int>> m(C, vector<int>(R));
        
        for ( int i = 0; i < R; i++) {
            for ( int j = 0; j < C; j++) {
                   m[j][i] = A[i][j]; 
            }
        }
        return m;
        
    }
};