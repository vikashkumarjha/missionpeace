/*
Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2

*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;



class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for ( int s = 0; s < nums.size(); s++) {
            int sum = 0;
            for ( int e = s ; e < nums.size(); e++) {
                sum += nums[e];
                if ( sum == k ){
                    count++;
                }
                
            }
            
        }
        return count;
        
    }
};

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        if ( nums.empty()) return 0;
        
        unordered_map<int,int> m;
        int curr = 0;
        m[0] = 1;
        int res = 0;
        for ( int i = 0; i < nums.size(); i++) {
            curr += nums[i];
            if ( m.count(curr - k)) {
                res += m[curr - k];
            }
            
            m[curr]++;
        }
        
        return res;
        
    }
};