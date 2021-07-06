Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false

class Solution {
public:
    bool helper(string &s, int l, int r, int k) {
        if ( l > r) {
            return true;
        }

        if ( s[l] == s[r]) {
            return helper(s, l+1, r-1, k);
        }

        return ( k  > 0) && (helper(s, l+1, r, k-1) || helper(s, l, r-1, k-1));

    }


    bool validPalindrome(string s) {
        int k = 1;
        int l = 0;
        int r = s.size() - 1;

        return helper(s, l, r, k);

    }
};
