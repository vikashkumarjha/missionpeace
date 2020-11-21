/*
 * Return the lexicographically smallest subsequence of text that contains all the distinct characters of text exactly once.

Example 1:

Input: "cdadabcc"
Output: "adbc"
Example 2:

Input: "abcd"
Output: "abcd"
Example 3:

Input: "ecbacba"
Output: "eacb"
Example 4:

Input: "leetcode"
Output: "letcod"

*/


class Solution {
public:
    string smallestSubsequence(string s) {
        string res = "";
        int last[26] = {}, seen[26] = {}, n = s.size();

        for (int i = 0; i < n; ++i)
            last[s[i] - 'a'] = i;


        for (int i = 0; i < n; ++i) {
            if (seen[s[i] - 'a']) continue;
            seen[s[i] - 'a']++;

            while (!res.empty() && res.back() > s[i] && i < last[res.back() - 'a']){
                seen[res.back() - 'a'] = 0, res.pop_back();
            }
            res.push_back(s[i]);
        }
        return res;

    }
};
