/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;




class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            unordered_set<string> dict(begin(wordList), end(wordList));
            queue<string> q;
            q.push(beginWord);

            vector<string> path;

            int dist = 0;

            while ( !q.empty()) {
                
                int qsize = q.size();
                ++dist;
                while ( qsize--) {
                
                auto w = q.front(); q.pop();
                if ( w == endWord) return dist;
                dict.erase(w);
                
                for ( int i = 0; i < w.size(); i++) {
                    auto ch = w[i];
                    for ( int k = 0; k < 26; k++) {
                        w[i] = 'a' + k;
                        if ( dict.count(w)) {
                            q.push(w);
                        }
                    }                    
                    w[i] = ch;
                }

                }
            }

            return 0;

        
    }
};

int main()
{
    Solution sol;
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    int res = sol.ladderLength("hit", "cog", wordList);
    cout << "\n The value of the result:" << res;
    return 0;
}