Given two strings s and t, find the number of ways you can choose a non-empty substring of s and replace a single character by a different character such that the resulting substring is a substring of t. In other words, find the number of substrings in s that differ from some substring in t by exactly one character.

For example, the underlined substrings in "computer" and "computation" only differ by the 'e'/'a', so this is a valid way.

Return the number of substrings that satisfy the condition above.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "aba", t = "baba"
Output: 6
Explanation: The following are the pairs of substrings from s and t that differ by exactly 1 character:
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
The underlined portions are the substrings that are chosen from s and t.
/*

Choose a start point for s and a start point for t, and then compare characters one by one.


Explanation
Try to match from s[i] and t[j],
where i = 0 or j = 0.

cur is the current number of consecutive same characters.
pre is the previous number of consecutive same characters.

*/

class Solution {
public:
    int countSubstrings(string s, string t) {
        int res = 0 ;
        for (int i = 0; i < s.length(); ++i)
            res += helper(s, t, i, 0);
        for (int j = 1; j < t.length(); ++j)
            res += helper(s, t, 0, j);
        return res;
    }

    int helper(string s, string t, int i, int j) {
        int res = 0, pre = 0, cur = 0;
        for (int n = s.length(), m = t.length(); i < n && j < m; ++i, ++j) {
            cur++;
            if (s[i] != t[j])
                pre = cur, cur = 0;
            res += pre;
        }
        return res;
    }
};