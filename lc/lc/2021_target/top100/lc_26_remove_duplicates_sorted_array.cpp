#include "../header.hpp"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int N = nums.size();
        if ( N == 0 ) return 0;
        int index = 0;
        for ( int i = 1; i < N; i++) {
            if ( nums[i-1] != nums[i]) {
                ++index;
                nums[index] = nums[i];
            }
        }
        return index + 1;
        
        
        
    }
};