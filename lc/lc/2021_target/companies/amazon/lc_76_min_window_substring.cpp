/*
Given two strings s and t, return the minimum window in s which will contain all the characters in t. If there is no such window in s that covers all characters in t, return the empty string "".

Note that If there is such a window, it is guaranteed that there will always be only one unique minimum window in s.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Example 2:

Input: s = "a", t = "a"
Output: "a"
*/

class Solution {
public:
    string minWindow(string s, string t) {
     int N1 = s.length();
     int N2 = t.length();
     
     // if the target length is more than sourse no window exists
     if ( N2 > N1) return "";
     
     int hash_pat[256] = {0};
     int hash_src[256] = {0};
     int minWindowSize = INT_MAX;
     
     // fill the hash of pattern
     for ( auto c : t) {
         hash_pat[c]++;
     }
     
     int l = 0;
     
     int index = -1;
     int count = 0;
     //lets start window
     for ( int r = 0; r < N1; r++) {
         hash_src[s[r]]++;
         
         if ( hash_pat[s[r]] != 0 && hash_src[s[r]] <= hash_pat[s[r]]) {
             count++;
         }
         // we have found the window
         if ( count == N2) {
             while ( hash_src[s[l]] > hash_pat[s[l]]
                    || hash_pat[s[l]] == 0
                    )
             {
                 if (  hash_src[s[l]] > hash_pat[s[l]]) {
                     hash_src[s[l]]--;
                 }
                 
                 l++;
               
             }
             
             int winLen = r - l + 1;
             if ( winLen < minWindowSize){
                 index = l;
                 minWindowSize = winLen;
             }
         }
         
     }
     
     return ( index == -1) ? "" : s.substr(index, minWindowSize);
     
        
    }
};