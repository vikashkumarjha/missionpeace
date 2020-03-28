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
        
          std::unordered_map<std::string,int> m;
        std::stringstream ss(paragraph);
        char delim = ' ';
        std::string token;
        std::string result;

        while ( std::getline(ss,token,delim))
        {
                if ( !token.empty())
                {
                        std::transform(token.begin(),token.end(),token.begin(), ::tolower);
                        token.erase(  std::remove_if( token.begin(),token.end(), [](char c) {
                                return std::isalnum(c) == 0;
                        }), token.end());
                        if ( std::find(banned.begin(),banned.end(),token) == banned.end())
                                m[token]++;
                }
        }

        std::vector<std::pair<std::string,int> > words ( m.begin(),m.end());
        std::sort ( words.begin(),words.end(), [ ] ( std::pair<std::string,int> a, std::pair<std::string,int> b) {
                return ( a.second > b.second);
        });

        return ( words.size() == 0 ) ?  result : words[0].first;
        
        
        
        
    }
};