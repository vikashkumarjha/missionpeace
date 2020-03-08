//
//  can_partition_equal_subset_sum.cpp
//  finishline
//
//  Created by vikash kumar jha on 10/31/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//
#if 0
#include <stdio.h>

bool helper(vector<int>& nums, int sum, int index){
    if ( index >= nums.size()) return false;
    if(sum == nums[index]) return true;
    if(sum < nums[index]) return false;
    return helper(nums,sum-nums[index],index+1) || helper(nums,sum,index+1);
}



bool canPartition(vector<int>& nums) {
 
    // first check the viability...
    
    int sum = 0;
    for ( auto n : nums){
        sum += n;
    }
    
    if ( sum %2 != 0)
    {
        return false;
    }
    
    
    sum /= 2;
    
    sort(nums.rbegin(), nums.rend());
    
    return helper(nums, sum, 0);
    
    
    
    
    
    
    
}

#endif
