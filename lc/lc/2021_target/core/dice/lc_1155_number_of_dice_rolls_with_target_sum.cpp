/*
You have d dice, and each die has f faces numbered 1, 2, ..., f.

Return the number of possible ways (out of fd total ways) modulo 10^9 + 7 to roll the dice so the sum of the face up numbers equals target.

 

Example 1:

Input: d = 1, f = 6, target = 3
Output: 1
Explanation: 
You throw one die with 6 faces.  There is only one way to get a sum of 3.
Example 2:

Input: d = 2, f = 6, target = 7
Output: 6
Explanation: 
You throw two dice, each with 6 faces.  There are 6 ways to get a sum of 7:
1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
Example 3:

Input: d = 2, f = 5, target = 10
Output: 1
Explanation: 
You throw two dice, each with 5 faces.  There is only one way to get a sum of 10: 5+5.
Example 4:

Input: d = 1, f = 2, target = 3
Output: 0
Explanation: 
You throw one die with 2 faces.  There is no way to get a sum of 3.
Example 5:

Input: d = 30, f = 30, target = 500
Output: 222616187
Explanation: 
The answer must be returned modulo 10^9 + 7.
 

Constraints:

1 <= d, f <= 30
1 <= target <= 1000




Let the function to find X from n dice is: Sum(m, n, X)
The function can be represented as:
Sum(m, n, X) = Finding Sum (X - 1) from (n - 1) dice plus 1 from nth dice
               + Finding Sum (X - 2) from (n - 1) dice plus 2 from nth dice
               + Finding Sum (X - 3) from (n - 1) dice plus 3 from nth dice
                  ...................................................
                  ...................................................
                  ...................................................
              + Finding Sum (X - m) from (n - 1) dice plus m from nth dice

So we can recursively write Sum(m, n, x) as following
Sum(m, n, X) = Sum(m, n - 1, X - 1) + 
               Sum(m, n - 1, X - 2) +
               .................... + 
               Sum(m, n - 1, X - m)

*/



//  The main function that returns number of ways to get sum 'x' 
//  with 'n' dice and 'm' with m faces. 
int findWays(int m, int n, int x) 
{ 
    // Create a table to store results of subproblems.  One extra  
    // row and column are used for simpilicity (Number of dice 
    // is directly used as row index and sum is directly used 
    // as column index).  The entries in 0th row and 0th column 
    // are never used. 
    int table[n + 1][x + 1]; 
    memset(table, 0, sizeof(table)); // Initialize all entries as 0 
  
    // Table entries for only one dice 
    for (int j = 1; j <= m && j <= x; j++) 
        table[1][j] = 1; 
  
    // Fill rest of the entries in table using recursive relation 
    // i: number of dice, j: sum 
    for (int i = 2; i <= n; i++) 
        for (int j = 1; j <= x; j++) 
            for (int k = 1; k <= m && k < j; k++) 
                table[i][j] += table[i-1][j-k]; 
  
    /* Uncomment these lines to see content of table 
    for (int i = 0; i <= n; i++) 
    { 
      for (int j = 0; j <= x; j++) 
        cout << table[i][j] << " "; 
      cout << endl; 
    } */
    return table[n][x]; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    cout << findWays(4, 2, 1) << endl; 
    cout << findWays(2, 2, 3) << endl; 
    cout << findWays(6, 3, 8) << endl; 
    cout << findWays(4, 2, 5) << endl; 
    cout << findWays(4, 3, 5) << endl; 
  
    return 0; 
} 



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
