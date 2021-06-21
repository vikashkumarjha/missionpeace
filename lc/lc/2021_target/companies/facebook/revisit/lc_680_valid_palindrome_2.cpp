/*
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.

*/

#include <iostream>
#include <string>

using namespace std;

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