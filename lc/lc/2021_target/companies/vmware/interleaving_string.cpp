class Solution {
public:
    bool helper(string s1, string s2, string s3, int idx1, int idx2, int idx3)
    {
       
        if ( idx1 == s1.size() && idx2 == s2.size() && idx3 == s3.size())
        {
            return true;
        }
        
        if ( idx3 == s3.size()) {
            return false;
        }
        
        
        
        return  (
                (( s1[idx1] == s3[idx3]) && helper(s1, s2, s3, idx1+1, idx2, idx3+1))
                ||
                 ( s2[idx2] == s3[idx3]) && helper(s1, s2, s3, idx1, idx2+1, idx3+1));
                 
        
    }
    
    
    bool isInterleave(string s1, string s2, string s3) {
        
        int n1 = s1.size() - 1;
        int n2 = s2.size() - 1;
        int n3 = s3.size() - 1;
        
        return helper(s1, s2, s3, 0, 0, 0);
        
        
    }
};


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        
        vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));
        
        for ( int i = 0; i <= n1; i++) {
            for ( int j = 0; j <= n1; j++) {
                if ( i == 0 && j == 0) {
                    dp[i][j] = 1;
                }
                else if ( i == 0) {
                    dp[i][j] = dp[i][j-1] && s3[i+j-1] == s2[j-1];
                }
                else if ( j == 0) {
                    dp[i][j] = dp[i-1][j] && s3[i+j-1] == s1[i-1];
                }
                else {
                    dp[i][j] = (dp[i][j-1] && s3[i+j-1] == s2[j-1]) ||
                               (dp[i-1][j] && s3[i+j-1] == s1[i-1]);
                }
                
            }
        }
        
        return dp[n1][n2] == 1;
        
        
    }
};