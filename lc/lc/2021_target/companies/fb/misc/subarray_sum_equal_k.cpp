//
//  subarray_sum_equal_k.cpp
//  finishline
//
//  Created by vikash kumar jha on 12/9/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

#include <iostream>
#include<unordered_map>
#include <vector>
using namespace std;


int subarraySum(vector<int>& nums, int k) {
    int count = 0;
    int n = static_cast<int>(nums.size());
    for ( int i = 0; i < n; i++){
        int curr_sum = 0;
        for ( int j = i; j < n; j++) {
            curr_sum += nums[j];
            if ( curr_sum == k)
                count++;
        }
    }
    return count;
    
}

int subarraySum2(vector<int> &nums, int k) {
    int count = 0;
    unordered_map<int,int> m;
    m.insert(make_pair(0,1));
    int sum = 0;
    for ( int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if ( m.count(sum - k ) ){
            count += m[sum-k];
        }
        m[sum]++;
    }
    return count;
    
    
}
