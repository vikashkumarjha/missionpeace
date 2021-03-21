
/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

*/


/****************************************************
Therefore, the DP function is:
   f(n) = min(f(n - 1 ^ 2), f(n - 2 ^ 2), ... ,f(n - m ^ 2)) + 1

****************************************************/
class Solution {
public:
    int numSquares(int n) {
        vector<int> DP(n + 1, INT_MAX);
        DP[0] = 0;
       
        for(int i = 1; i <= n; i++) {
            int m = sqrt(i);
       
            for (int j = 1; j <= m; j++) {
                 if (DP[i - j*j] != INT_MAX)
                     DP[i] = min(DP[i],  DP[i - j*j] + 1);
            }
        }
           
        return DP[n];
    }
};
