/*
Given a list of words, each word consists of English lowercase letters.

Let's say word1 is a predecessor of word2 if and only if we can add exactly one letter anywhere in word1 to make it equal to word2.  For example, "abc" is a predecessor of "abac".

A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1, where word_1 is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.

Return the longest possible length of a word chain with words chosen from the given list of words.

 

Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chain is "a","ba","bda","bdca".

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int longestStrChain(vector<string>& words) {
        if ( words.empty()) return 0;
        sort(begin(words), end(words), [](auto a, auto b){
           return a.size() < b.size(); 
        });
        
        unordered_map<string,int> dp;
        int res = 0;
        
        for ( int i = 0; i < words.size(); i++)
        {
            int currMax = 0;
            for ( int j = 0; j < words[i].size(); j++)
            {
                string curr = words[i];
                string w = curr.substr(0, j) + curr.substr(j+1);
                currMax = max(currMax, dp[w] + 1);
                
            }
            dp[words[i]] = currMax;
            res = max(res, currMax);
            
        }
        
        return res;
        
    }
};