/*
Given an m x n binary matrix filled with 0's and 1's, 
find the largest square containing only 1's and return its area.

*/


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int M = matrix.size(); 
        int N = M > 0 ? matrix[0].size() : 0;
        vector<vector<int>> dp(M+1, vector<int>(N+1,0));
        int maxsqlen = 0;
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (matrix[i-1][j-1] == '1'){
                    dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
                    maxsqlen = max(maxsqlen, dp[i][j]);
                }
            }
        }
        return maxsqlen * maxsqlen;
        
    }
};
/*****************************************************
0 1   1 1
1 1   1 1
    
1 0
1 1
    
1 1
0 1
****************************************************/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
       
        int R = matrix.size();
        int C = matrix[0].size();
       
        vector<vector<int>> lookup(R, vector<int>(C, 0));        
        int maxLength = 0;
       
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
               
                lookup[i][j] = (matrix[i][j] - '0');        
                if (i && j && matrix[i][j] == '1')
                    lookup[i][j] = 1 + min(lookup[i - 1][j - 1] , min(lookup[i][j - 1], lookup[i - 1][j]));
               
                maxLength = max(maxLength, lookup[i][j]);  
            }
        }
       
        return maxLength*maxLength;
    }
};

