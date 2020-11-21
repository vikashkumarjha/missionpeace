/*
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

Example 1:

Input: 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
Example 2:

Input: 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
Note: You may assume that n is not less than 2 and not larger than 58.

*/


/**************************************
1 2 3 4 5 6 7 8 9 10
-->---------------->
---->-------------->
------>------------>
------->----------->


Any number n, which is greater than 2, can be break into the sum of 2 possitive integers, namely, x and y. 
Obviously, x + y = n. Then our objective function is divided into subproblems:
    f(n) = max { max( f(x) * f(y), x * f(y), f(x) * y, x*y) | x = 1, 2, ..., n - 1 }

with base condition : f(1) = 1, f(2) = 1. 

1  2  3  4  5  6  7  8  9 
--------->
            ------------>
   j         (i - j)          
*****************************************************************/

/**************************************/
class Solution {
public:
    int integerBreak(int n) {
      if ( n < 2) return 0;
    
    vector<int> DP(n+1, 0);
    DP[1] = 1;
    DP[2] = 1;
    
    for ( int i = 3; i <= n; i++) {
        int maxProduct = 0;
        
        for ( int j = 1; j < i; j++) {
            int left = j;
            int right = i - j;
            auto max1 = max( left * right, left * DP[right]);
            auto max2 = max(DP[right] * DP[left], DP[left] * right);
            maxProduct = max(maxProduct, max(max1, max2));
           
        }
        DP[i] = maxProduct;
        
    }
    
    return DP[n];
        
    }
};