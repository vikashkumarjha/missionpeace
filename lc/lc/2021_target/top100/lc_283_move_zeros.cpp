
/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]


*/

#include "../header.hpp"
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int writeIndex = 0;
        int n = nums.size();
        for ( int i = 0; i < n; i++) {
            if ( nums[i] != 0) {
                nums[writeIndex] = nums[i];
                writeIndex++;
            }
        }
        for ( int i = writeIndex; i < n; i++) {
            nums[i] = 0;
        }
    }
};


class Solution2 {
public:
    void moveZeroes(vector<int>& nums) {
        int zero_index = 0;
        for ( int i = 0; i < nums.size(); i++)
        {
                if ( nums[i] != 0 ) {
                        std::swap(nums[i],nums[zero_index++]);
                }
        }
        
    }
};

int main()
{
    vector<int> nums = {0,1,0,3,12};
    Solution2 s;
    s.moveZeroes(nums);
    for_each(nums.begin(), nums.end(), [](int x) {
        cout << x << " ";
    });
}