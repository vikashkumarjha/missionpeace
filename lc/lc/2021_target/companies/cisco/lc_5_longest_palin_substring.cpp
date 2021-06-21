/*
 * Given a string s, return the longest palindromic substring in s.
 *
 *
 *
 *  Example 1:
 *
 *  Input: s = "babad"
 *  Output: "bab"
 *  Note: "aba" is also a valid answer.
 *
 *  */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    bool isPalindrome(string s)
    {
        bool result = true;
        int r = s.size() - 1;
        int l = 0;

        while ( l < r)
        {
            if ( s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        int maxLength = 1;
        vector<string> res;
        string curr;
        // pick the starting point..
        for ( int i = 0; i < n; i++)
        {
            // now length
            for ( int len = 1; len <= n - i; len++)
            {
                string s1 = s.substr(i, len);
                if ( isPalindrome(s1)) {
                    // update the result if the current
                    if (s1.size() > curr.size() ) {
                        curr = s1;
                    }
                }
            }
        }

        for_each(begin(res), end(res), [](string a) {
                cout << "\n " << a;
        });
        return curr;
    }
};


string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1));
    int startIdx = -1;
    int maxLen = 0;

    for ( int len=1; len <= n; len++)
    {
        if ( len == 1) {
            for ( int i = 1; i <= n; i++)
            {
                dp[i][i] = 1;
                startIdx = i - 1;
                maxLen = len;
            }
        }
        else if ( len == 2) {
            for ( int i = 1; i <= n; i++)
            {
                if ( s[i-1] == s[i]) {
                    dp[i][i+1] = 1;
                    startIdx = i -1;
                    maxLen = len;
                }
            }
        }
        else {
            for ( int i = 1; i <= ( n - len + 1); i++)
            {
                    int j = i + len - 1;
                    if ( s[i-1] == s[j-1] && dp[i+1][j-1]) {
                        startIdx = i - 1;
                        maxLen = len;
                        dp[i][j] = 1;
                    }
            }
        }
    }

    return s.substr(startIdx, maxLen);
}













int main()
{
    Solution sol;
    string x = sol.longestPalindrome("babad");
    cout << "\n Result:" << x;
    return 0;

}
