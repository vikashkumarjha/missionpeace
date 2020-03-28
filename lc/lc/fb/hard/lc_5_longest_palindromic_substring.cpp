/*
 *Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

 Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

*/
#include "header.hpp"
using namespace std;


string longestPalindrome(string s) {
    if ( s.empty() ) return "";
    int L = s.length();
    vector<vector<int>> DP(L+1, vector<int>(L+1, 0));

    int startIdx = 0;
    int maxLen = 0;

    for ( int l = 1; l <= L; l++) {
        if ( l == 1) {
            for ( int i = 1; i <= L; i++) {
                DP[i][i] = 1;
                startIdx = i - 1;
                maxLen = 1;
            }
        }else if ( l == 2) {
            for ( s[i] == s[i-1]) {
                DP[i][i+1] = 1;
                startIdx = i -1;
                maxLen = 2;
            }
        }else {
            for ( int i = 1;i <= L - l + 1; i++) {
                int j = i + l - 1;
                if ( DP[i+1][j-1]  && s[i-1] == s[j-1]) {
                    DP[i][j] = 1;
                    startIdx = i - 1;
                    maxLen = l;
                }
            }
        }
    }
    return s.substr(startIdx, maxLen);
}


