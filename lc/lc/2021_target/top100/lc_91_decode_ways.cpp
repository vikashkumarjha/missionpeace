/*
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 *
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 *
 * Example 1:
 *
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 *
 * */
#include "../header.hpp"

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if ( n == 0 || s[0] == '0')
            return 0;

        vector<int> dp(n+1);
        dp[0] = 1;
        for ( int i = 1; i <= n; i++){
            if ( s[i] != '0') dp[i] = dp[i-1];
            if ( i >= 2) {
                auto  v = stoi(s.substr(i-2,2));
                if ( v  >= 10 && v  <= 26) {
                    dp[i] += dp[i-2];
                }
            }
        }
        return dp[n];
    }
};


int main()
{
    Solution s;
    cout << "\n Number of decodings:" << s.numDecodings("226");
    return 0;
}
