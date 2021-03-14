/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//aab
// every index of the string can be starting point

class Solution {
public:

    void dfs(string &s, int idx, vector<string> &curr, vector<vector<string>> &res) {
        if ( idx >= s.length()) {
            res.push_back(curr);
            return;
        }

        for ( int end = idx; end < s.size(); end++) {
            if ( isPalindrome(s, idx, end)) {
                curr.push_back(s.substr(idx, end - idx+ 1));
                dfs(s, end + 1, curr, res);
                curr.pop_back();
            }
        }
    }
    bool isPalindrome(string &s, int l, int r) {
        while ( l < r) {
            if ( s[l] != s[r]) {
                return false;
            }
            l++; 
            r--;
        }
        return true;
    }



    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> currList;
        dfs(s, 0, currList, res);
        return res;
    }
};


int main()
{
    string s = "aab";
    Solution sol;
    vector<vector<string>> res = sol.partition(s);
    for ( auto row : res) {
        cout << "\n";
        for ( auto c : row) {
            cout << c << " ";
        }
    }
}