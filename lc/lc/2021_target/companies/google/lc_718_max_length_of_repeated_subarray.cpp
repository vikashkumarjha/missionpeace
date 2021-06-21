/*
Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

 

Example 1:

Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].
Example 2:

Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5
*/


class Solution {
public:
    int res = 0;
    
    int helper(vector<int> &nums1, int idx1, vector<int> &nums2, int idx2) {
        if ( idx1 >= nums1.size() || idx2 >= nums2.size()) return 0;
        int subResult = 0;
        
        if ( nums1[idx1] == nums2[idx2]) {
            subResult = 1 + helper(nums1, idx1+1, nums2, idx2+1);
            res = max(subResult, res);
        }
        helper(nums1, idx1+1, nums2, idx2);
        helper(nums1, idx1, nums2, idx2+1);
        
        return subResult;
        
        
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        helper(nums1, 0, nums2, 0);
        return res;
        
    }
};

class Solution {
public:
    int res = 0;
    
    int helper(vector<int> &nums1, int idx1, vector<int> &nums2, int idx2 , vector<vector<int>> &dp) {
        if ( idx1 >= nums1.size() || idx2 >= nums2.size()) return 0;
        
        if ( dp[idx1][idx2] != -1) {
            return dp[idx1][idx2];
        }
        
        int subResult = 0;
        
        if ( nums1[idx1] == nums2[idx2]) {
            subResult = 1 + helper(nums1, idx1+1, nums2, idx2+1, dp);
            res = max(subResult, res);
        }
        helper(nums1, idx1+1, nums2, idx2, dp);
        helper(nums1, idx1, nums2, idx2+1, dp);
        
        dp[idx1][idx2] = subResult;
        
        return subResult;
        
        
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> dp(n1, vector<int>(n2,-1));
        helper(nums1, 0, nums2, 0, dp);
        return res;
        
    }
};



class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size(), ans = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};


