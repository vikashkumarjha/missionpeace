/*
Given a string s, find the length of the longest substring without repeating characters.



 Example 1:

 Input: s = "abcabcbb"
 Output: 3
 Explanation: The answer is "abc", with the length of 3.
 Example 2:

 Input: s = "bbbbb"
 Output: 1
 Explanation: The answer is "b", with the length of 1.
 Example 3:

 Input: s = "pwwkew"
 Output: 3
 Explanation: The answer is "wke", with the length of 3.
 Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

 */

#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;

        int l = 0;
        int r = 0;
        unordered_map<int,int> m;
        int res = 0;

        for (;r < s.size(); r++)
        {
            if ( m.count(s[r])) {
                l = max(l, m[s[r]]);
            }
            res = max(res, r - l + 1);
            m[s[r]] = r+1;
        }
        return res;

    }
};

int main()

{
    vector<string> input = {
        "abcabcbb",
        "bbbb",
        "abcdefghaaaa",
        "a"
    };

    Solution sol;

    for ( auto x : input) {
        int r = sol.lengthOfLongestSubstring(x);
        cout << "\n " << x << " :: " << r;
    }

    return 0;


}
