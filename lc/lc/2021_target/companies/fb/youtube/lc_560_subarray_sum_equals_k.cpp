/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2


*/


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
    int count = 0;
    int sum = 0;
    std::unordered_map<int,int> m;
    m.insert(std::make_pair(0,1));

    for ( int i = 0; i < nums.size(); i++){
        sum += nums[i];
        if ( m.count(sum - k)){
            count += m[sum-k];
        }
        
        m[sum] += 1;
    }
    
    return count;

        
    }
};