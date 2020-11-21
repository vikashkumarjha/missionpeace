#include "header.hpp"
using namespace std;

/*
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find
 * the one that is missing from the array.
 *
 * Example 1:
 *
 * Input: [3,0,1]
 * Output: 2
 * Example 2:
 *
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 *
 *
 *
*/


/*
class Solution {
    public int missingNumber(int[] nums) {
        int missing = nums.length;
        for (int i = 0; i < nums.length; i++) {
            missing ^= i ^ nums[i];
        }
        return missing;
    }
}

*/




int missingNumber(vector<int>& nums) {
    set<int> s(nums.begin(), nums.end());

    int N = nums.size() + 1;

    for ( int i = 0; i < N; i++) {
        if ( !s.count(i)) {
            return i;
        }
    }

    return -1;

}
