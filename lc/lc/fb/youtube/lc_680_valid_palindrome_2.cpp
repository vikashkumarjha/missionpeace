/*
 * Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
*/

class Solution {
public:
    bool validPalindrome(string s) {
        return valid(s, 0, s.length() - 1, 1);
    }

private:
    bool valid(string& s, int i, int j, int d) { // d: num of chars you can delete at most
        if (i >= j) return true;
        if (s[i] == s[j])
            return valid(s, i + 1, j - 1, d);
        else
            return d > 0 && (valid(s, i + 1, j, d - 1) || valid(s, i, j - 1, d - 1));
    }
};
