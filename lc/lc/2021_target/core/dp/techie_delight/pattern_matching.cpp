/*
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*' where: 

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

*/



#include "../../header.hpp"
#include <stdio.h>
#include <string.h>
 
// defines maximum length of pattern or input string
#define LEN 20
 
// create a DP lookup table
int lookup[LEN][LEN];
 
// Function that matches input string with given wildcard pattern
int isMatching(char str[], char pattern[], int n, int m)
{
    // If both input string and pattern reaches their end,
    // return true
    if (m < 0 && n < 0)
        return 1;
 
    // If only pattern reaches its end, return false
    else if (m < 0)
        return 0;
 
    // If only input string reaches its end, return true
    // if remaining characters in the pattern are all '*'
    else if (n < 0)
    {
        for (int i = 0; i <= m; i++)
            if (pattern[i] != '*')
                return 0;
 
        return 1;
    }
 
    // If the sub-problem is encountered for the first time
    if (lookup[m][n] == -1)
    {
        if (pattern[m] == '*')
        {
            // 1. * matches with current characters in input string.
            // Here we will move to next character in the string
 
            // 2. Ignore * and move to next character in the pattern
            lookup[m][n] = isMatching(str, pattern, n - 1, m) ||
                        isMatching(str, pattern, n, m - 1);
        }
        else
        {
            // If the current character is not a wildcard character, it
            // should match with current character in the input string
            if (pattern[m] != '?' && pattern[m] != str[n])
                lookup[m][n] = 0;
 
            // check if pattern[0..m-1] matches str[0..n-1]
            else
                lookup[m][n] = isMatching(str, pattern, n - 1, m - 1);
        }
    }
 
    return lookup[m][n];
}



// Function that matches input string with given wildcard pattern
bool isMatching(string str, string pattern)
{
    // get length of string and wildcard pattern
    int n = str.length();
    int m = pattern.length();
 
    // create a DP lookup table
    // all elements are initialized by false by default
    bool T[n+1][m+1];
 
    // if both pattern and string is empty: match
    T[0][0] = true;
 
    // handle empty string case (i == 0)
    for (int j = 1; j <= m; j++)
        if (pattern[j-1] == '*')
            T[0][j] = T[0][j-1];
 
    // build matrix in bottom-up manner
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (pattern[j-1] == '*')
                T[i][j] = T[i-1][j] || T[i][j-1];
 
            else if (pattern[j-1] == '?' || str[i-1] == pattern[j-1])
                T[i][j] = T[i-1][j-1];
        }
    }
 
    // last cell stores the answer
    return T[n][m];
}
 
// Wildcard Pattern Matching
int main(void)
{
    char str[] = "xyxzzxy";
    char pattern[] = "x***x?";
 
    memset(lookup, -1, sizeof(lookup));
 
    if (isMatching(str, pattern, strlen(str) - 1, strlen(pattern) - 1))
        printf("Match");
    else
        printf("No Match");
 
    return 0;
}



