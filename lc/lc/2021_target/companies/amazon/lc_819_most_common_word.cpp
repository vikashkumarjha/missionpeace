/*
Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.  It is guaranteed there is at least one word that isn't banned, and that the answer is unique.

Words in the list of banned words are given in lowercase, and free of punctuation.  Words in the paragraph are not case sensitive.  The answer is in lowercase.

 

Example:

Input: 
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
Output: "ball"
Explanation: 
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"), 
and that "hit" isn't the answer even though it occurs more because it is banned.

*/


class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        
        unordered_map<string,int> m;
        unordered_set<string> dict(begin(banned), end(banned));
        int freq = INT_MIN;
        string res;
        string w;
        for ( auto c : paragraph) {
            if ( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ) {
                w += c;
            }else {
                if ( !w.empty()) {
                    
                    transform(w.begin(), w.end(), w.begin(), ::tolower);
                    if ( !dict.count(w)) {
                        m[w]++;
                           
                        if ( m[w] > freq) {
                            freq = m[w];
                            res = w;
                        }
                    }
                    w = "";
                }
            }
        }
        if ( !w.empty()) {
             transform(w.begin(), w.end(), w.begin(), ::tolower);
                    if ( !dict.count(w)) {
                        m[w]++;
                        
                        if ( m[w] > freq) {
                            freq = m[w];
                            res = w;
                        }
                    }
            
        }
        
        return res;
        
        
    }
};