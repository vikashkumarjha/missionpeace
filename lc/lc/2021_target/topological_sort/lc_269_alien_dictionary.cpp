/*
There is a new alien language that uses the English alphabet. However, the order among letters are unknown to you.

You are given a list of strings words from the dictionary, where words are sorted lexicographically by the rules of this new language.

Derive the order of letters in this language, and return it. If the given input is invalid, return "". If there are multiple valid solutions, return any of them.

 

Example 1:

Input: words = ["wrt","wrf","er","ett","rftt"]
Output: "wertf"
Example 2:

Input: words = ["z","x"]
Output: "zx"

*/
#include "header.hpp"

class Solution {
public:
    string alienOrder(vector<string>& words) {
        if ( words.empty()) return "";
        unordered_map<char,unordered_set<char>> g;
        unordered_map<char,int> indegree;

        for ( auto w : words) {
            for ( auto c : w) {
                indegree[c] = 0;
            }
        }

        for ( int i = 0; i < words.size() - 1; i++) {
            string curr = words[i];
            string next = words[i+1];
            int len = min(curr.size(), next.size());
            bool flag = 

            for (int j = 0; j < len; j++)
            {
                if (curr[j] != next[j])
                {
                    unordered_set<char> neigh = g[curr[j]];
                    if (!neigh.count(next[j]))
                    {
                        g[curr[j]].insert(next[j]);
                        indegree[next[j]]++;
                    }
                    break;
                }
                if (j == len - 1 && curr.size() > next.size())
                    return "";
            }
        }

        string ans;
        queue<char> q;
        for ( auto p : indegree) {
            if (p.second == 0) {
                q.push(p.first);
            }
        }

        while ( !q.empty()) {
            auto ch = q.front(); q.pop();
            ans += ch;
            if (g[ch].size() > 0 ) {
                for ( auto &n : g[ch]) {
                    indegree[n]--;
                    if ( indegree[n] == 0) {
                        q.push(n);
                    }
                }
            }
        }
        return ( ans.length() == indegree.size()) ? ans : "";

        
    }
};