/*
Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode"
return 2.

*/

#include "header.hpp"


class Solution {
public:
    int firstUniqChar(string s) {

        unordered_map<char,int> m;
        for ( auto c : s) {
            m[c]++;
        }

        for ( int i = 0; i < s.length(); i++) {
            if ( m[s[i]] == 1) return i;
        }
        return -1;

       
    }
};
