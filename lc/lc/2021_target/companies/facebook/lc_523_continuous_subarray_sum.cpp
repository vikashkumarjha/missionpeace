/*

Given an integer array nums and an integer k, return true if nums has a continuous subarray of size at least two whose elements sum up to a multiple of k, or false otherwise.

An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.

 

Example 1:

Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
Example 2:

Input: nums = [23,2,6,4,7], k = 6
Output: true
Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.

*/

/*
From this observation, we come to the conclusion that whenever 
the same sum%ksum value is obtained corresponding to two indices ii and jj, it implies that sum of elements betweeen those indices is an integer multiple of kk. Thus, if the same sum%ksum value is encountered again during the traversal, 
we return a \text{True}True directly.

*/



   bool checkSubarraySum(vector<int>& nums, int k) {
         if (nums.size() < 2)
             return false;
        
        unordered_map<int, int> hash;
        hash[0] = -1;
        
        int totalsum = 0;
        for (int i = 0; i < nums.size(); i++) {
            totalsum += nums[i];
            
            if (k != 0)
                totalsum = totalsum % k;
        
            if (hash.count(totalsum)) 
            {
                // Here we check for self Index
                if (i - hash[totalsum] > 1)
                    return true;
            } 
            else 
            {
                hash[totalsum] = i;
            }
        }
        
        return false;
    }
    
};