Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int n = s.size();
        int res = 0;
        unordered_map<char,int> m;
        for (r; r < n; r++) {
            if (m.count(s[r])) {
                l = max(l, m[s[r]]);
            }
            res = max(res, r - l+1);
            m[s[r]] = r+1;
        }

        return res;
        
    }
};