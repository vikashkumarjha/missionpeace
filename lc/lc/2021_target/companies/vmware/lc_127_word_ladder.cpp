/*
A transformation sequence from word beginWord to word endWord using a 
dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in 
the shortest transformation sequence from beginWord to endWord, \
or 0 if no such sequence exists.



 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(begin(wordList), end(wordList));
        queue<string> q;
        q.push(beginWord);
        int res = 0;

        while (!q.empty()) {
            auto qsize = q.size();
            res++;
            while (qsize--) {
                auto w = q.front(); q.pop();
                if ( w == endWord) {
                    return res;
                }
                dict.erase(w);
                for ( int i = 0; i < w.size(); i++) {
                    char ch = w[i];
                    for ( int j = 0; j < 26; j++) {
                        w[i] = 'a' + j;
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