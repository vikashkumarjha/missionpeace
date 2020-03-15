/*
 * Balanced strings are those who have equal quantity of 'L' and 'R' characters.

Given a balanced string s split it in the maximum amount of balanced strings.

Return the maximum amount of splitted balanced strings.



Example 1:

Input: s = "RLRRLLRLRL"
Output: 4
Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.

*/

class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0, cnt = 0;
        for (const auto& c : s) {
            cnt += c == 'L' ? 1 : -1;
            if (cnt == 0) ++res;
        }
        return res;

    }
};
