/*
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:

Return true if there exists i, j, k
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.

Example 1:

Input: [1,2,3,4,5]
Output: true
*/

#include "../header.hpp"

//10,20,3,2,1,1,2,0,4


/*
first_num = second_num = some very big number
for n in nums:
    if n is smallest number:
        first_num = n
    else if n is second smallest number:
        second_num = n
    else n is bigger than both first_num and second_num:
        # We have found our triplet, return True

*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX;
        int b = INT_MAX;

        for ( auto n : nums) {
            if ( n <= a) {
                a = n;
            }
            else if ( n <= b ) {
                b = n;
            } else {
                return true;
            }
        }

        
    }
};