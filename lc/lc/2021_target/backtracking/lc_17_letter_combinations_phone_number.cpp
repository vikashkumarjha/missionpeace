#include "../header.hpp"
using namespace std;


class Solution {
public:

    void helper(string &digits, string &curr, vector<string> &dict, vector<string> &res) {
        if ( digits.length() == curr.length()) {
            if ( !curr.empty())
                res.push_back(curr);
            return;
        }

        int idx = digits[curr.length()] - '0';
        for ( int i = 0; i < dict[idx].length(); i++) {
            curr.push_back(dict[idx][i]);
            helper(digits, curr, dict, res);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        string curr;
        vector<string> res;
        vector<string> dict = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        helper(digits, curr, dict, res);
        return res;
    }
};


int main()
{
    Solution s;
    vector<string> res = s.letterCombinations("23");
    for ( auto r : res) {
        cout << "\n[" << r << "]";
    }

    return 0;

}
