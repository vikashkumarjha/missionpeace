#include "../header.hpp"

/*
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 *
 * Example:
 *
 * Input: [10,9,2,5,3,7,101,18]
 * Output: 4
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore the
 * length is 4.
 * Note:
 *
 * There may be more than one LIS combination, it is only necessary for you to
 * return the length.
 * Your algorithm should run in O(n2) complexity.
 *
 * */

class Solution {
public:

    int helper(vector<int> &a, int n, int &globalMax) {
        if (n == 1) return 1;
        int localMax= 1;
        int res;

        for (  int i = 1; i < n; i++) {
            res = helper(a, i, globalMax);
            if ( a[i-1] < a[n-1] && res + 1 > localMax) {
                localMax = res + 1;
            }
        }
        globalMax = max(globalMax, localMax);
        return localMax;
    }
    int lis(vector<int> &nums) {
        int result= 1;
        helper(nums, nums.size(), result);
        return result;
    }

    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();

        if ( N == 0) return 0;
        int result = 0;
        result = lis(nums);
        return result;
    }
};
class Solution2 {
public:
    int lengthOfLIS(vector<int>& a) {
        int N = a.size();
        if ( N == 0) return 0;

        vector<int> dp(N,1);
        for ( int i = 1; i < N; i++)
        {
            for ( int j = 0; j < i; j++){
                if ( a[j] < a[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};




int main()
{
    vector<int> a = {10, 22, 9, 33, 21, 50, 41, 60 };
    Solution2 s;
    cout << "\n Lis " << s.lengthOfLIS(a);
    return 0;

}
