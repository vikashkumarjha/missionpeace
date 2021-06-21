/*

To some string s, we will perform some replacement operations that replace groups of letters with new ones (not necessarily the same size).

Each replacement operation has 3 parameters: a starting index i, a source word x and a target word y. The rule is that if x starts at position i in the original string S, then we will replace that occurrence of x with y. If not, we do nothing.

For example, if we have s = "abcd" and we have some replacement operation i = 2, x = "cd", y = "ffff", then because "cd" starts at position 2 in the original string s, we will replace it with "ffff".

Using another example on s = "abcd", if we have both the replacement operation i = 0, x = "ab", y = "eee", as well as another replacement operation i = 2, x = "ec", y = "ffff", this second operation does nothing because in the original string s[2] = 'c', which doesn't match x[0] = 'e'.

All these operations occur simultaneously. It's guaranteed that there won't be any overlap in replacement: for example, s = "abc", indexes = [0, 1], sources = ["ab","bc"] is not a valid test case.

 

Example 1:

Input: s = "abcd", indexes = [0, 2], sources = ["a", "cd"], targets = ["eee", "ffff"]
Output: "eeebffff"
Explanation:
"a" starts at index 0 in s, so it's replaced by "eee".
"cd" starts at index 2 in s, so it's replaced by "ffff".

*/

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        
        int m = sources.size();
        int n = S.length();
        unordered_map<int, pair<string, int>>mp;
        
        for (int i = 0; i < m; i++) {
            if (S.substr(indexes[i], sources[i].length()) == sources[i])
                mp[indexes[i]] = make_pair(targets[i], sources[i].length());
        }
        
        string ans;
        for (int i = 0; i < S.length(); i++) {
            if (mp.find(i) != mp.end()) {
                ans += mp[i].first;
                i += mp[i].second-1;
            } else {
                ans += S[i];
            }
        }
        
        return ans;
    }
};