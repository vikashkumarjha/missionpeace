//
//  majority_element_2.cpp
//  finishline
//
//  Created by vikash kumar jha on 12/27/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

/*
 Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 Note: The algorithm should run in linear time and in O(1) space.

 Example 1:

 Input: [3,2,3]
 Output: [3]
 Example 2:

 Input: [1,1,1,3,3,2,2,2]
 Output: [1,2]
 */
#if 0
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> result;
        
        int count1=0, count2=0;
        int result1=INT_MAX, result2=INT_MAX;
        
        for(int num:nums){
            if(num==result1) count1++;
            else if(num==result2) count2++;
            else if(count1==0) { result1=num; count1=1; }
            else if(count2==0) { result2=num; count2=1; }
            else { count1--; count2--; }
        }
        
        count1=count2=0;
        for(int num:nums){
            if(num==result1) count1++;
            else if(num==result2)  count2++;
        }
        
        cout<<result1<<":"<<count1<<endl;
        cout<<result2<<":"<<count2<<endl;
        
        if(count1>n/3) result.push_back(result1);
        if(count2>n/3) result.push_back(result2);
        
        return result;
    }
};

#endif
