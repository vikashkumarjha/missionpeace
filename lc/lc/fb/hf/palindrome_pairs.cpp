
/*
Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:

Input: ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]] 
Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","lls


*/

class Solution {
public:
    bool isPalindrome(string &s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i] != s[j])
                return false;
            ++i, --j;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<string, int> m;
        for (int i = 0; i < words.size(); ++i) {
            string temp = words[i];
            reverse(temp.begin(), temp.end());
            m[temp] = i;
        }
        
        for (int i = 0; i < words.size(); ++i) {
            for (int len1 = 0; len1 <= words[i].length(); ++len1) {
                string prefix = words[i].substr(0, len1), suffix = words[i].substr(len1);
                
                if (isPalindrome(prefix) && m.count(suffix) && m[suffix] != i)
                    ans.push_back({m[suffix], i});
                
                if (!suffix.empty() && isPalindrome(suffix) && m.count(prefix) && m[prefix] != i)
                    ans.push_back({i, m[prefix]});
            }
        }
        return ans;
    }
};