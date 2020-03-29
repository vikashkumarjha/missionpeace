/*
You have d dice, and each die has f faces numbered 1, 2, ..., f.

Return the number of possible ways (out of fd total ways) modulo 10^9 + 7 to roll the dice so the sum of the face up numbers equals target.

 

Example 1:

Input: d = 1, f = 6, target = 3
Output: 1
Explanation: 
You throw one die with 6 faces.  There is only one way to get a sum of 3.

*/


class Solution {
public :
    vector<vector<int>> DP = vector(31, vector<int>(1001, INT_MIN));

    int numRollsToTarget(int d, int f, int target) {
        if (d == 0 || target <= 0)
            return d == target;
       
        if (DP[d][target] != INT_MIN) return DP[d][target];
 
        int totalWays = 0;
        for (int i = 1; i <= f; ++i)
            totalWays = (totalWays + numRollsToTarget(d - 1, f, target - i)) % 1000000007;
 
        DP[d][target] = totalWays;
        return totalWays;
    }
};