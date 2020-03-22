/*
 * Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4


*/

#include "header.hpp"
using namespace std;


// we are trying  to find the longest palindrome subsequence
//

int lpsHelper(string &s, int l, int r) {
    // base case only one char
    if ( l == r) return 1;
    // only 2 chars
    if ( s[l] == s[r] && l+1 == r) {
        return 2;
    }

    if ( s[l] == s[r]) {
        return 2 + lpsHelper(s, l+1, r-1);
    }
    return max( lpsHelper(s, l+1, r) , lpsHelper(s, l, r-1));
}


int lps(string s) {
    if ( s.empty() )
        return 0;

    int l = 0;
    int r = s.length() - 1;

    return lpsHelper(s, l, r);

}


class Solution {
public:
    int longestPalindromeSubseq(string str) {
        int n = str.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
        }

        for(int L = 2; L <= n; L++){
            for(int i = 0; i <= n - L; i++){
                int j = i + L- 1;

                if(str[i] == str[j] && L == 2)
                {
                    dp[i][j] = 2;
                }
                else if(str[i] == str[j])
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else
                {

                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
         }

         return dp[0][n - 1];
    }
};


int main() {

    string s = "GEEKSFORGEEKS";

    std::cout << "\n The longest palindrome subsequence" << lps(s);
    return 0;
}



