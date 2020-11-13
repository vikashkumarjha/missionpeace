#include "../header.hpp"
using namespace std;



class Solution {
public:

    void helper(int n , string curr, int left, int right, vector<string> &res) {
        if ( curr.length() == 2 * n) {
            res.push_back(curr);
            return;
        }

        if (left < n) {
            helper(n, curr + "(" , left + 1, right, res);
        }

        if (right < left) {
            helper(n, curr + ")" , left , right + 1, res);
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
    Solution s;
    vector<string> r = s.generateParenthesis(2);
    for ( auto s : r) {
        cout << "\n [ " << s << "]";
    }
    return 0;

}
