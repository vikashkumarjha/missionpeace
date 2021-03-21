#include "../header.hpp"

class Solution {
public:

    void helper(string &digits, int idx, string curr, unordered_map<int, string> &m , vector<string> &res) {
        if ( idx == digits.size()) {
            res.push_back(curr);
            return;
        }

        int d = digits[idx] - '0';
        
        for ( int k = 0; k < m[d].size(); k++) {
            curr.push_back(m[d][k]);
            helper(digits, idx + 1, curr, m, res);
            curr.pop_back();
        }

    }


    vector<string> letterCombinations(string digits) {
        unordered_map<int, string> m = {
            {0, ""},
            {1, ""},
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"},
        };

        if ( digits.empty()) return vector<string>{};

        vector<string> res;

        helper(digits, 0, "", m, res);

        return res; 
        
    }
};