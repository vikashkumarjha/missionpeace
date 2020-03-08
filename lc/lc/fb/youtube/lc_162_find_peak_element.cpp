
#if 0
#include "header.hpp"
using namespace std;


int findPeakElement(vector<int>& nums) {
    if ( nums.empty())
        return -1;
    int l = 0;
    int r = nums.size() - 1;

    while ( l < r) {
        int m = l + ( r - l) / 2;
        if ( nums[m] > nums[m+1]) {
            r = m;
        }else {
            l = m + 1;
        }
    }
    return l;
}

#endif
