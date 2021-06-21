/*
Given a string s, return true if a permutation of the string could form a palindrome.

 

Example 1:

Input: s = "code"
Output: false
Example 2:

Input: s = "aab"
Output: true
Example 3:

Input: s = "carerac"
Output: true
*/

class Solution {
public:
    bool canPermutePalindrome(string s) {

    std::unordered_map<char,int>  charMap;
    for ( int i = 0; i < s.length(); ++i)
    {
        charMap[s[i]]++;
    }
    int oddCount = 0;
    for ( auto it = charMap.begin(); it != charMap.end(); ++it){
        if (it->second % 2 != 0 ){
            oddCount++;
        }
    }  
    return ( oddCount <= 1);
        
}
};