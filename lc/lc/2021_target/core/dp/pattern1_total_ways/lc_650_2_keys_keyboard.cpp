/*Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:

Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
 

Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted. Output the minimum number of steps to get n 'A'.

Example 1:

Input: 3
Output: 3
Explanation:
Intitally, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.

*/




class Solution {
public:
        
    // dp vector to store <step,value> result for using in future
    int dp[1001][1001];
    
    int minKeyPress(int step, int value, int copy, int&n)
    {
        // impossible case when step>n or value>n, so return INT_MAX
        if(step>n || value>n) return INT_MAX;
        
        // reached target value and so return step 
        if(value==n) return step;
        
        // return recalculated value
        if(dp[step][value]!=-1) return dp[step][value];
        
        // return min step to reach the target value
        // there are 2 choices: paste copied value with current value => 1 step
        // copy current value and paste it with itself => 2 step
        return dp[step][value] = min(minKeyPress(step+1,value+copy,copy,n),
        minKeyPress(step+2,2*value,value,n));
    }
    
    int minSteps(int n) {
    
        // base case : n==1 no steps needed
        if(n==1) return 0;
        
        memset(dp,-1,sizeof(dp));
        
        // start with value 1 and copy 1 and intial step 1 (assuming we already copied the intial value 'A')
        return minKeyPress(1,1,1,n);
    }
};