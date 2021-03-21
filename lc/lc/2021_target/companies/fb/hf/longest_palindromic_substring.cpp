
string longestPalindromicSubstring(string s) {
    int n = s.length();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    int maxLen = 0;
    int startIdx = 0;

    for ( int l = 1; l <= n; l++) {
        if ( l == 1) {
            for ( int i = 1; i <= L; i++) {
                dp[i][i] = 1;
                maxLen = l;
                startIdx = i;
            }
        }
        else if ( l == 2) {
            for ( int i = 1; i < n; i++) {
                if ( s[i] == s[i-1]) {
                    dp[i][i+1] = 1;
                    startIdx = i - 1;
                    maxLen = l;
                }
            }
        }
        else {
            for ( int i = 1; i <= n - l + 1 ; i++) {
                int j = i + l  - 1;
                if ( dp[i+1][j-1] && s[i-1] == s[j-1]) {
                    dp[i][j] = 1;
                    maxLen = l;
                    startIdx = i - 1;
                }

            }

        }
        return s.substr(startIdx , maxLen);

    }






}
