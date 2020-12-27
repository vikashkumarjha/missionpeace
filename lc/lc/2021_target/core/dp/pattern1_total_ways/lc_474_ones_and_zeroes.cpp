/*
You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.

 

Example 1:

Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.


*/

#include "../../header.hpp"


typedef vector<int> v1d;
typedef vector<v1d> v2d;
typedef vector<v2d> v3d;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l = strs.size();
        v3d dp(l+1, v2d(m+1, v1d(n+1, 0))); //dp[l+1][m+1][n+1]
        
        for(int i=1;i<=l;i++)
        {
            string s = strs[i-1];
            int ones = count(s.begin(), s.end(), '1');
            int zeros = s.size()-ones;
            
            for (int j=0;j<=m;j++)
            {
                for (int k=0;k<=n;k++)
                {
                    if (j>=zeros && k>=ones)
                        dp[i][j][k] = max(dp[i-1][j][k], 1 + dp[i-1][j-zeros][k-ones] );
                    else
                        dp[i][j][k] = dp[i-1][j][k];
                    
                }//k
            }//j
        }//i
        
        return dp[l][m][n];
    }
};