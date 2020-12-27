/*
We have a collection of rocks, each rock has a positive integer weight.

Each turn, we choose any two rocks and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.  Return the smallest possible weight of this stone (the weight is 0 if there are no stones left.)

 
 */


/*
Same problem as:
Divide all numbers into two groups,
what is the minimum difference between the sum of two groups.
Now it's a easy classic knapsack problem.


Brief Prove
All cases of "cancellation of rocks" can be expressed by two knapsacks.
And the last stone value equals to the difference of these two knapsacks
It needs to be noticed that the opposite proposition is wrong.


Solution 1
Explanation:
Very classic knapsack problem solved by DP.
In this solution, I use dp to record the achievable sum of the smaller group.
dp[x] = 1 means the sum x is possible.

*/


class Solution {
public:
    int lastStoneWeightII(vector<int>& A) {
        
        vector<bool> dp(1501, false);
        dp[0] = true;
        int sumA = 0;
        for (int a : A) {
            sumA += a;
            for (int i = min(1500, sumA); i >= a; --i)
                dp[i] =  (dp[i] || dp[i - a]);
        }
        for (int i = sumA / 2; i >= 0; --i)
            if (dp[i]) return sumA - i - i;
        return 0;
        
    }
};


class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        
        int n = stones.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += stones[i];
        
        vector<int>dp(sum/2+1, false);
        int target = sum/2;
        dp[0] = true;
        
        for (int i = 0; i < n; i++) {
            for (int j =  target; j >= stones[i]; j--) {
                dp[j] = dp[j] | dp[j-stones[i]];
            }
        }
        
        for (int i = sum/2; i >= 0; i--) {
            if (dp[i]) return sum-i-i;
        }
        
        return 0;
    }
};