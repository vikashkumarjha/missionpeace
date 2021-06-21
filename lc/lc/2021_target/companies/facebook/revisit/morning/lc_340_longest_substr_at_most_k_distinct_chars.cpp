/*
Given a string s and an integer k, return the length of the longest substring of s that contains at most k distinct characters.

 

Example 1:

Input: s = "eceba", k = 2
Output: 3
Explanation: The substring is "ece" with length 3.
Example 2:

Input: s = "aa", k = 1
Output: 2
Explanation: The substring is "aa" with length 2.

*/


class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int l = 0;
        int r = 0;
        int result = INT_MIN;
        unordered_map<char,int> hash;
        
        for ( r; r < s.length(); r++) {
            hash[s[r]]++;
            if ( hash.size() > k ) {
                result = max(result, r - l);
                while ( hash.size() > k ) {
                    if ( --hash[s[l++]] == 0  ){
                        hash.erase(s[l-1]);
                    }
                }
            }
        }
        result = max(result, r - l);
        return result;
        
    }
};