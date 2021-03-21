/*
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words.
 *
 * Note:
 *
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * Example 1:
 *
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * */


// intution
//
//
#include "../header.hpp"

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if ( s.empty()) return false;
        int n = s.length();
        set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> isVisited(n+1,false);
        queue<int> q;
        q.push(0);
        while ( !q.empty()) {
            auto index = q.front(); q.pop();
            if ( !isVisited[index]) {
                for ( int r = index+1; r <= n; r++) {
                    auto tok = s.substr(index,  r - index);
                    if ( dict.count(tok)) {
                        q.push(r);
                        if ( r == n)return true;
                    }
                }
                isVisited[index] = true;
            }
        }
        return false;
    }
};

int main()
{
    vector<string> dict = {"leet", "code", "i"};
    Solution s;
    auto r = s.wordBreak("leetcodei", dict);
    auto toPrint =  (r) ? "possible" : "not possible";
    cout << "\n " << toPrint;
    return 0;
}
