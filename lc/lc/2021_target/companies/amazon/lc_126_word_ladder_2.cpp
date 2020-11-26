/*
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.

*/
class Solution {
public:
    
   // Here we form List of words having diff of 1 char from Original Word
    vector<string> 
    getNextWords (string word, unordered_set<string> & wordhash) {
        vector<string> result;
        
        for (auto & x : word){
            auto x1 = x;
            
            for (char x2 = 'a'; x2 <= 'z'; x2++){
                x = x2;
                if (wordhash.count(word))
                    result.push_back(word);
            }
            
            x = x1;
        }
        
        return result;
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<vector<string>> q;
        vector<vector<string>> res;
        
        q.push({beginWord});
        unordered_set<string> dict(begin(wordList) , end(wordList));
        
        
        while (!q.empty()) {
            auto qsize = q.size();
            unordered_set<string> isVisited;
            
            while ( qsize--) {
                auto curr = q.front(); q.pop();
                string w = curr.back();
                vector<string> ret = getNextWords(w, dict);
                
                for ( auto str : ret) {
                    auto currX = curr;
                    currX.push_back(str);
                    isVisited.insert(str);
                    
                    if ( str == endWord) {
                        res.push_back(currX);
                    }else {
                        q.push(currX);
                    }
                }
                
            }
            for ( auto str : isVisited) {
                dict.erase(str);
            }
         
        }
        return res;
        
        
      
        
    }
};