Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true

class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
         unordered_map<char, char>ms, mt;
        for (int i = 0; i < s.size(); ++i) {
            if (ms.count(s[i]) && mt.count(t[i])) {
                if (ms[s[i]] != t[i]) {
                    return false;
                }
            } else if (ms.count(s[i]) || mt.count(t[i])) {
                return false;
            } else {
                ms[s[i]] = t[i];
                mt[t[i]] = s[i];
            }
        }
        return true;
    }

};