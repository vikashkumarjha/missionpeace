/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

*/

// [ 1, 2, 3 , 4]

//     1. 1  2   6
 //   24   12  4   1         


#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> l(n,1);
        vector<int> r(n,1);
        vector<int> res(n);
        for ( int i = 1; i < n; i++) {
            l[i] = nums[i-1] * l[i-1];
        }
        
       for ( int i = n - 2; i >= 0; i--) {
            r[i] = nums[i+1] * r[i+1];
       }
       for ( int i = 0; i < n; i++) {
           res[i] = l[i] * r[i];
       } 
      
        return res;
        
        
    }
};