/*
You are given an array of strings words and a string chars.

A string is good if it can be formed by characters from chars (each character can only be used once).

Return the sum of lengths of all good strings in words.

 

Example 1:

Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: 
The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.

*/

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        vector<int> v(26);
        int cnt = 0;
        
        for (auto c : chars) {
            v[c - 'a']++;
        }
        
        for (auto w : words) {
            vector<int> cmp(26);
            for (auto c : w) {
                cmp[c - 'a']++;
            }
            
            bool suc = true;
            for (int i = 0; i < 26; i++) {
                if (cmp[i] > v[i]){
                    suc = false;
                    break;
                }
            }
            
            if (suc) {
                cnt += w.size();
            }
            
        }
        
        return cnt;
        
    }
};