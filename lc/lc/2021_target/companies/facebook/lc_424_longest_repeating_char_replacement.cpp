/*
ou are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
 
 */


class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0, maxf = 0;
        unordered_map<int, int> count;
        for (int r = 0; r < s.length(); ++r) {
            
            
            maxf = max(maxf, ++count[s[r]]);
            if (res - maxf < k)
                res++;
            else
                count[s[r - res]]--;
        }
        return res;
        
    }
};