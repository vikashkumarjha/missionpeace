/*
 * You are given a license key represented as a string S which consists only alphanumeric character and dashes. The string is separated into N+1 groups by N dashes.

Given a number K, we would want to reformat the strings such that each group contains exactly K characters, except for the first group which could be shorter than K, but still must contain at least one character. Furthermore, there must be a dash inserted between two groups and all lowercase letters should be converted to uppercase.

Given a non-empty string S and a number K, format the string according to the rules described above.

Example 1:
Input: S = "5F3Z-2e-9-w", K = 4

Output: "5F3Z-2E9W"

Explanation: The string S has been split into two parts, each part has 4 characters.
Note that the two extra dashes are not needed and can be removed.

*/


class Solution {
public:
     string licenseKeyFormatting(string S, int K) {
        if (K <= 0)
            return "";
        string res, tmp;
        for (int i = S.size() - 1; i >= 0; i--) {
            char c = S[i];
            if (c != '-') {
                tmp += toupper(c);
            }
            if (tmp.size() == K) {
                res += "-" + tmp;
                tmp = "";
            }
        }
        if (tmp.size())
            res += "-" + tmp;
        if (res.size())
            res = res.substr(1);
        reverse(res.begin(), res.end());
        return res;
    }
};
