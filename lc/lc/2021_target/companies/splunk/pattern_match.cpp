/*
 *
 * Check a string and pattern containing wildcard characters write an efficient
 * algorithm to check if the string matcher with the wildcard pattern or not */


/*
 *  ? => matches a any single character
 *  * => matches zero or more character
 *
 *  */


#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;


bool helper(string s, int idx1, string p, int idx2)
{
    if ( idx1 == s.size())
    {
        for ( int i = idx2; i < p.size(); i++)
        {
            if ( p[i] != '*')
                return false;
        }
        return true;
    }

    if ( idx2 == p.size())
    {
        return idx1 == s.size();
    }

    if ( p[idx2] == '?' || p[idx2] == s[idx1])
    {
        return helper(s, idx1+1, p, idx2+1);
    }
    if ( p[idx2] == '*')
    {
        return helper(s, idx1+1, p, idx2) or helper(s, idx1, p, idx2+1);
    }
    return false;

}


bool isMatch(string s, string p) {
    return helper(s, 0, p, 0);
}


// memo
//

// Recursive function to check if the input string matches
// with a given wildcard pattern
bool isMatch(string str, int n,
            string pattern, int m,
            unordered_map<string, bool> &lookup)
{
    // construct a unique map key from dynamic elements of the input
    string key = to_string(n) + "|" + to_string(m);

    // if the subproblem is seen before
    if (lookup.find(key) != lookup.end()) {
        return lookup[key];
    }

    // since the subproblem is seen for the first time, solve it and
    // store its result in a map

    // end of the pattern is reached
    if (m == pattern.size())
    {
        // return true only if the end of the input string is also reached
        return (lookup[key] = (n == str.size()));
    }

    // if the input string reaches its end, return when the
    // remaining characters in the pattern are all `*`

    if (n == str.size())
    {
        for (int i = m; i < pattern.size(); i++)
        {
            if (pattern[i] != '*') {
                return (lookup[key] = false);
            }
        }

        return (lookup[key] = true);
    }

    // if the current wildcard character is `?` or the current character in
    // the pattern is the same as the current character in the input string

    if (pattern[m] == '?' || pattern[m] == str[n])
    {
        // move to the next character in the pattern and the input string
        lookup[key] = isMatch(str, n + 1, pattern, m + 1, lookup);
    }

    // if the current wildcard character is `*`
    else if (pattern[m] == '*')
    {
        // move to the next character in the input string or
        // ignore `*` and move to the next character in the pattern

        lookup[key] = isMatch(str, n + 1, pattern, m, lookup) ||
            isMatch(str, n, pattern, m + 1, lookup);
    }
    else {
        // we reach here when the current character in the pattern is not a
        // wildcard character, and it doesn't match the current
        // character in the input string

        lookup[key] = false;
    }

    return lookup[key];
}

// Check if a string matches with a given wildcard pattern
bool isMatch(string str, string pattern)
{
    unordered_map<string, bool> lookup;
    return isMatch(str, 0, pattern, 0, lookup);
}


// DP

class Solution {
public:
    bool isMatch(string s, string p) {
        int S = s.length();
        int P = p.length();

        vector<vector<int>>  DP(S + 1, vector<int>(P + 1, false));
        DP[0][0] = true;

        // Here we mark initial * as matching for anything True
        for (int i = 1; i <= P; i++) {
            if (p[i - 1] != '*')
                break;

            DP[0][i] = true;
        }

        for (int i = 1; i <= S; i++) {
            for (int j = 1; j <= P; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                {
                    DP[i][j] = DP[i - 1][j - 1];
                }
                else if (p[j - 1] == '*')
                {
                    DP[i][j] = DP[i][j - 1] || DP[i - 1][j];
                }
            }
        }

        return DP[S][P];
    }
};



int main()
{
    string s = "XYXZZXY";
    string p = "X***Y";

    if ( isMatch(s, p)) {
        cout << "\n Matched";
    }else {
        cout << "\n Not Matched";
    }
}
