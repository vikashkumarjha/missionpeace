/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False

*/


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        vector<int> v1(256,0),v2(256,0);
        int n = s1.size();
        if(n>s2.size()) return false;
        for(int i = 0; i < n; ++i)
        {
            ++v1[s1[i]];
            ++v2[s2[i]];
        }
        if(v1==v2) return true;
        for(int i = n; i < s2.size(); ++i)
        {
            ++v2[s2[i]];
            --v2[s2[i-n]];
            if(v1 == v2) return true;
        }
        return false;
        
    }
};