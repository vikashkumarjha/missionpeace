#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
class Solution {
private:
    unordered_map<int,int> m;
    int helper(int idx, string &s) {
        if (s[idx] == 0) return 0;

        if ( idx >= s.length() - 1) {
            return 1;
        }

        if ( m.count(idx)) return m[idx];

        int subResult = helper(idx + 1, s);
        if ( stoi(s.substr(idx ,2)) >= 1 && stoi(s.substr(idx , 2)) <= 26 ) {
            subResult += helper(idx+2, s);
        }
        m[idx] = subResult;
        return subResult;
    }
public:
    int numDecodings(string s) {
        return helper(0, s);
    }
};

class Solution2 {
public:
    int numDecodings(string s) {
        int n = s.length();
        if ( n == 0 || s[0] == '0') return 0;

        vector<int> dp(n+1, 0);
        dp[0] = 1;

        for ( int i = 1; i < n; i++) {
            if ( s[i-1] != '0') {
                dp[i] = dp[i-1];
            }
            if ( i >= 2 ) {
                int v = stoi(s.substr(i-2, 2));
                if ( val > 9 && val <= 26) {
                    dp[i] += dp[i-2];
                }
            }
        }
        return dp[n];
    }
};





int main()
{
    string str = "226";
    Solution s;
    int r = s.numDecodings(str);
    cout << "\n Result" << r;
    return 0;

}
