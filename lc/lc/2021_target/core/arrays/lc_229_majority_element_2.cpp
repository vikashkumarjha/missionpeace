/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Follow-up: Could you solve the problem in linear time and in O(1) space?

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
*/


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int N = nums.size();
        vector<int> result;
        
        if ( N < 2 ) {
            return nums;
        }
        int majElem1 = INT_MAX;
        int majElem2 = INT_MAX;
        int count1 = 0;
        int count2 = 0;
        for ( auto n : nums) {
            if ( majElem1 == n) {
                count1++;
            }else if ( majElem2 == n) {
                count2++;
            }
            else if ( count1 == 0) {
                majElem1 = n;
                count1 = 1;
            }
             else if ( count2 == 0) {
                majElem2 = n;
                count2 = 1;
            }
            
            else {
                count1--;
                count2--;
                
            }
        }
        
        count1=count2=0;
        for(int num:nums){
            if(num==majElem1) count1++;
            else if(num==majElem2)  count2++;
        }
        
        
        
        if(count1>N/3) result.push_back(majElem1);
        if(count2>N/3) result.push_back(majElem2);
        
        
        return result;
    }
};