#include "../header.hpp"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int n = s.size();
        unordered_map<char,int> m;
        int result = 0;
        for (; r < n; r++) {
            if ( m.count(s[r])) {
                l = max(l, m[s[r]]);
            }
            result = max(result, r - l + 1);
            m[s[r]] = r + 1;
        }
        return result;
    }
};


int main()
{
    Solution s;
    vector<string> input = {"abcabcbb", "bbbbb", "pwwkew", ""};
    for (auto x : input){
        cout << x << "::" << s.lengthOfLongestSubstring(x) << "\n";
    }
    return 0;
}