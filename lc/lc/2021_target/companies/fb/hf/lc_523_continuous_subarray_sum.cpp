/*

Given a list of non-negative numbers and a target integer k, write a function to check if the array has a continuous subarray of size at least 2 that sums up to a multiple of k, that is, sums up to n*k where n is also an integer.

 

Example 1:

Input: [23, 2, 4, 6, 7],  k=6
Output: True
Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.


*/


 bool checkSubarraySum(vector<int>& nums, int k) {
     if (  nums.size() < 2) return false;

     unordered_map<int,int> m;
     int totalSum = 0;
    for ( int i = 0 ; i < nums.size(); i++) {
         totalSum += nums[i];
         if ( k != 0) {
             totalSum = totalSum % k;
         }
         if ( m.count(totalSum)) {
             if ( i - m[count] > 1) return true;
         }
         m[totalSum] = i;
     }

     return false;


 }
