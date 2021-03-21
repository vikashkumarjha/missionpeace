/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.


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
#include <set>

using namespace std;


class Solution {
private:
    vector<bool> isVisited;
    bool dfs(string s, int idx, unordered_set<string>& wordDict) {
        
        if (idx == s.length())
            return true;
        
        for (int i = idx + 1; i <= s.length(); i++) {
            string prefix = s.substr(idx, i - idx);
            
            if (wordDict.count(prefix)) {
                
                string after = s.substr(i);
                if (!isVisited[i]) {
                    if (dfs(s, i, wordDict))
                        return true;
                    else
                        isVisited[i] = true;
                }
            }
        }
        
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        isVisited.resize(s.length()+1, false);
        unordered_set<string> dict(begin(wordDict), end(wordDict)); 
        return dfs(s, 0, dict);
    }
};


class Solution2 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict(wordDict.begin(), wordDict.end());
        queue<int> q;
        q.push(0);
        vector<bool> isVisited(s.length()+1, false);
        
        while ( !q.empty()) {
            auto index = q.front(); q.pop();
            if ( !isVisited[index]) {
                for ( int r = index + 1; r <= s.length(); r++) {
                    auto token = s.substr(index, r - index);
                    if ( dict.find(token) != dict.end()){
                        q.push(r);
                        if ( r == s.length())
                            return true;
                    }
                    
                }
                
                isVisited[index] = true;
            }
            
        }
        return false;
    
        
    }
};


class Solution3 {
public:
   bool wordBreak(string s, vector<string>& wordDict) {

    std::set<string> wordDictSet(wordDict.begin(), wordDict.end());
    std::vector<bool> dp(s.length() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= s.length(); i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && 
                wordDictSet.find(s.substr(j, i-j)) != wordDictSet.end()) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.length()];

}
};