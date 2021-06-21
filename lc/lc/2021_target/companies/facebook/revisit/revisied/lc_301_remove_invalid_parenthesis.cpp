/*
 * Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return all the possible results. You may return the answer in any order.



Example 1:

Input: s = "()())()"
Output: ["(())()","()()()"]
Example 2:

Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]
Example 3:

Input: s = ")("
Output: [""]

*/

#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>

using namespace std;


class Solution {

private:

    void helper(const string &s, int idx, int removeLeft, int removeRight, int pair, string curr, unordered_set<string> &res)
    {
        if ( idx == s.size())
        {
            if ( removeLeft == 0 && removeRight == 0 && pair == 0) {
                res.insert(curr);
            }
            return;
        }

        if ( s[idx] == '(') {
            if ( removeLeft > 0 ) {
                helper(s, idx+1, removeLeft-1, removeRight, pair, curr, res);
            }
            helper(s, idx+1, removeLeft, removeRight, pair+1, curr + s[idx], res);
        }
        else  if ( s[idx] == ')') {
            if ( removeRight > 0 ) {
                helper(s, idx+1, removeLeft, removeRight-1, pair, curr, res);
            }
            if ( pair > 0)
             helper(s, idx+1, removeLeft, removeRight, pair-1, curr + s[idx], res);
        }
        else {
            helper(s, idx+1, removeLeft, removeRight, pair, curr + s[idx], res);
        }
    }

public:
    vector<string> removeInvalidParenthesis(string s) {
        unordered_set<string> result;
        int removeLeft = 0;
        int removeRight = 0;
        int pair = 0;

        for ( int i = 0; i < s.size(); i++)
        {
            if ( s[i] == '(') {
                removeLeft++;
            }
            else if ( s[i] == ')') {
                if ( removeLeft > 0) --removeLeft;
                else
                    removeRight++;
            }

        }
        helper(s, 0, removeLeft, removeRight, pair, "", result);
        return vector<string>(begin(result), end(result));
    }
};


int main()
{
    Solution sol;
    string s = "()())()";
    vector<string> r =sol.removeInvalidParenthesis(s);
    for ( auto x : r) {
        cout << "\n [" << x << "]";
    }

    return 0;

}
