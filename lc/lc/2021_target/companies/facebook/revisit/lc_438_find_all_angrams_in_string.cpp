/*
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

*/


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> mS(256,0);
        vector<int> mP(256, 0);
        int n1 = s.size();
        int n2 = p.size();
        if ( n1 < n2 ) return {};
        
        vector<int> res;
        for ( int i = 0; i < n2; i++) {
            mS[s[i]]++;
            mP[p[i]]++;
        }
        if ( mS == mP) 
            res.push_back(0);
        
        
        for ( int r = n2; r < n1; r++) {
           mS[s[r]]++;
           mS[s[r-n2]]--;
           if ( mS == mP) {
               res.push_back(r - p.size() + 1);
           }
            
        }
        
        return res;
        
        
    }
};