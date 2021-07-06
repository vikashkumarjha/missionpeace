/*
 * Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.



Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

*/


class Solution {
public:
    bool isPalindrome(string s) {
        if ( s.empty()) return true;
        int l = 0;
        int r = s.size() - 1;

        while ( l < r) {
            while ( l < r && !isalnum(s[l])) l++;
            while ( l < r && !isalnum(s[r])) r--;
            if ( toupper(s[l]) != toupper(s[r])) return false;
            l++;
            r--;

        }
        return true;



    }
};
