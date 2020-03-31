/*
Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.

 

Example 1:

Input: A = "ab", B = "ba"
Output: true
Example 2:

Input: A = "ab", B = "ab"
Output: false
Example 3:

Input: A = "aa", B = "aa"
Output: true

*/

class Solution {
public:
    bool buddyStrings(string A, string B) {
        
        if (A.length() != B.length()) return false;
        
        // if both strings are equal then there should be rep char
        if (A == B && set<char>(A.begin(), A.end()).size() < A.size()) return true;
        vector<int> dif;
        for (int i = 0; i < A.length(); ++i) {
            if (A[i] != B[i])                              
                dif.push_back(i);
        }
        return dif.size() == 2 && A[dif[0]] == B[dif[1]] && A[dif[1]] == B[dif[0]];
        
    }
};