
/*
 * Given a text and a wildcard pattern, implement wildcard pattern matching
 * algorithm that finds if wildcard pattern is matched with text. The matching
 * should cover the entire text (not partial text).
 * The wildcard pattern can include the characters ‘?’ and ‘*’
 * ‘?’ – matches any single character
 * ‘*’ – Matches any sequence of characters (including the empty sequence)
 *
 *
 * */

#include <iostream>
#include <string>
#include <vector>

using namespace std;



int matcher(string &s, string &p, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 && j < 0)
        return 1;


    if ( j < 0)
        return 0;

    if ( i < 0 )
    {
        while ( j >= 0 )
        {
            if ( p[j] != '*')
                return 0;
            j--;
        }
        return 1;
    }

    if ( dp[i][j] != -1)
    {
        if ( p[j] == '*') {
            return dp[i][j] = matcher(s, p, i-1, j, dp) || matcher(s, p, i, j - 1, dp);
        }
        else {
            if ( s[i] != p[j]  && p[j] != '?')
            {
                dp[i][j] = 0;
            }
            else {
                dp[i][j] = matcher(s, p, i-1, j-1, dp);
            }
        }
    }
    return dp[i][j];
}


bool isMatching(string s, string p) {
    int n = s.size();
    int m = p.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
    matcher(s, p, n-1, m-1, dp);
    return dp[n][m];
}



bool isMatchingVersion2(string s, string p)
{
    int n = s.size();
    int m = p.size();

    if ( m == 0)
        return n == 0;

    vector<vector<int>> dp(n+1, vector<int>(m+1, false));
    dp[0][0] = true;
    // only * can match the empty char
    for ( int j = 1; j <= m; j++)
    {
        if ( p[j-1] == '*')
        {
            dp[0][j] = dp[0][j-1];
        }
    }

    for ( int i = 1; i <= n; i++)
    {
        for ( int j = 1; j <= m; j++)
        {
            if ( p[j-1] == '*')
            {
                dp[i][j] = dp[i][j-1] || dp[i-1][j];
            }
            else if ( p[j-1] == '?' || s[i-1] == p[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }
    return dp[n][m];
}

int main()
{
    string str = "baaabab";
    string pattern = "*****ba*****ab";
    if (isMatching(str, pattern))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    if (isMatchingVersion2(str, pattern))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
