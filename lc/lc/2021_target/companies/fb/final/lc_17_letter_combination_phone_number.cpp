class Solution {
public:

    void helper(string digits, int idx, string &curr, unordered_map<int,string> &m, vector<string> &res)
    {
        if ( idx >=  digits.size()) {
            if ( curr.size() == digits.size()) {
                res.push_back(curr);
                return;
            }
        }

        string w = m[digits[idx] - '0'];
        for ( int i = 0; i < w.size(); i++)
        {
            curr.push_back(w[i]);
            helper(digits, idx + 1, curr, m, res);
            curr.pop_back();

        }


    }


    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if ( digits.empty()) return res;

        unordered_map<int, string> m = { 
            {0, ""}, {1,""}, {2, "abc"}, {3, "def"}, {4, "ghi"}, {5,"jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}
        };
        string path;

        helper(digits, 0, path, m, res);
        return res;


    }
};
