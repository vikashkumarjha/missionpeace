/*
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 *
 *
 *
 *  Example 1:
 *
 *  Input: n = 3
 *  Output: ["((()))","(()())","(())()","()(())","()()()"]
 *  Example 2:
 *
 *  Input: n = 1
 *  Output: ["()"]
 *
 *  */

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    void helper(int n, string curr, int left, int right, vector<string> &res) {

        if ( curr.size() == 2 * n) {
            res.push_back(curr);
            return;
        }
        if ( left < n) {
            helper(n, curr + "(" , left + 1, right, res);
        }
        if ( right < left) {
            helper(n, curr + ")", left, right+1, res);
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr;
        helper(n, curr, 0, 0, res);
        return res;

    }
};


int main()
{
    Solution sol;
    vector<string> res = sol.generateParenthesis(3);

    for ( auto x : res) {
        cout << "\n" << x;
    }

    return 0;


}
