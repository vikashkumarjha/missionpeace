//
//  continuous_subarray_sum.cpp
//  finishline
//
//  Created by vikash kumar jha on 2/6/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <list>
#include <stack>
#include <map>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <numeric>


using namespace std;


#if 0

class Solution {
public:
    // Here we Iterate and have cummulative Sum of numbers
    //  -- Keep checking is Sum is Multiple of K
    // Use logic X - Y = K*ABC.
    
    
    /*
    From this observation, we come to the conclusion that whenever the same sum%ksum value is obtained corresponding to two indices ii and jj, it implies that sum of elements betweeen those indices is an integer multiple of kk.
    
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

#endif
