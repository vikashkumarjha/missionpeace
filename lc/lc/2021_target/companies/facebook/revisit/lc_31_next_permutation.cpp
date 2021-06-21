/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]

*/
#include <iostream>
#include<vector>
#include <string>
#include <algorithm>

using namespace std;





class Solution {
public:
    void nextPermutation(vector<int>& nums) {
            if ( nums.empty() || nums.size() == 1) return;
            int n = nums.size();
            int r = n - 1;
            int pos = -1;
            bool flag = true;
            for (  ;r >= 0; r--) {
                if ( nums[r] > nums[r-1]) {
                    pos = r - 1;
                    flag = false;
                    break;
                }                
           }
           if ( flag){
               sort(begin(nums),end(nums));
               return;
           }
           
           int x = nums[pos];
           int y = nums[pos+1];
           int idx = pos + 1;

           for ( int i = pos+2; i < n; i++) {
               if ( nums[i] > x && nums[i] < y) {
                   idx = i;
                   y = nums[i];
               }
           }
           nums[pos] = y;
           nums[idx] = x;

           sort(nums.begin() + pos + 1, nums.end());

    }
};

int main()
{
    Solution sol;
    vector<int> a = {1,1,5};
    sol.nextPermutation(a);
    for_each(begin(a), end(a), [](int x) {
        cout << x << " ";
    });

    return 0;
}