#include "header.hpp"
using namespace std;

/*
 * Given an input string (s) and a pattern (p), implement regular expression
 * matching with support for '.' and '*'.
 *
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * The matching should cover the entire input string (not partial).
 *
 * Note:
 *
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters like
 * . or *.
 * Example 1:
 *
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * Example 2:
 *
 * Input:
 * s = "aa"
 * p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the preceding element, 'a'. Therefore,
 * by repeating 'a' once, it becomes "aa".
 *
 *
 * */

vector<vector<int>> DP;


bool helper(int i, int j, string s, string p) {

    if (DP[i][j] != -1) return DP[i][j];

    bool result;

    if (j == p.size()) {
        result = (i == s.size());
    } else {
        bool isFirstCMatch = (i < s.size() && (p[j] == s[i] || p[j] == '.'));

        if (j + 1 < p.size() && p[j + 1] == '*')
            result = (helper(i, j + 2, s, p) ||
                    (isFirstCMatch && helper(i + 1, j, s, p)));
        else
            result = isFirstCMatch && helper(i + 1, j + 1, s, p);
    }

    DP[i][j] = result;
    return result;

}



bool isMatch(string s, string p) {
    int S = s.size();
    int P = p.size();
    DP.resize(S+1, vector<int>(P+1, -1));

     //DP = vector<int>(S+1, vector<int>(P+1, -1));
    helper(0, 0, s , p);

    for ( int i = 0; i <= S; i++) {
        std::cout << "\n";
        for ( int j = 0; j <= P; j++) {
            std::cout << DP[i][j] << " ";
        }
    }


    return DP[S][P] == 1;

}


int main() {
    string s = "aab";
    string     p = "c*a*b";
    if ( isMatch(s, p)) {
        std::cout << "\n Both matches...";
    }

}
