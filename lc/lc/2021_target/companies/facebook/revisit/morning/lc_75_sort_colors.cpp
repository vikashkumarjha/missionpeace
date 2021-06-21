/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int smaller = 0;
        int equal = 0;
        int larger = nums.size();
        
        while ( equal < larger) {
            if ( nums[equal] < 1) {
                swap(nums[smaller++], nums[equal++]);
              
            }
            else if ( nums[equal] == 1) {
                ++equal;
            }
            else {
                swap(nums[equal], nums[--larger]);
                
            }
            
        }
        
    }
}; 