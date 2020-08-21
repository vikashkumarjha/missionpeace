/*
Given a string, find the length of the longest substring T that contains at most k distinct characters.

Example 1:

Input: s = "eceba", k = 2
Output: 3
Explanation: T is "ece" which its length is 3.
Example 2:

Input: s = "aa", k = 1
Output: 2
Explanation: T is "aa" which its length is 2.

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
                    if ( --hash[s[l]] == 0  ){
                        hash.erase(s[l]);
                    }
                    l++;
                }
            }
        }
        result = max(result, r - l);
        return result;
        
    }
};