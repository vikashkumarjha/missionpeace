/*
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).



Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

*/

#include <iostream>
#include <vector>

using namespace std;


double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    if ( n1 > n2) {
        return findMedianSortedArrays(nums2, nums1);
    }
    int halfLen = ( n1 + n2 +1 ) / 2;
    int l = 0;
    int r = n1;

    while ( l <= r)
    {
        int idx1 = ( l + r) / 2;
        int idx2 = halfLen - idx1;

        if ( idx1 < r && nums2[idx2-1] > nums1[idx1])
        {
            l = idx1 + 1;
        }
        else if ( idx1 > l &&  nums1[idx-1] > nums2[idx2])
        {
            r = idx - 1;
        }
        else {

            int a = 0;
            if ( idx1 == 0 ) {
                a = nums2[idx2-1];
            }

            else if ( idx2 == 0 ) {
                a = nums1[idx1-1];
            }
            else {
                a = max(nums1[idx1-1], nums2[idx2-1]);
            }

            if ( (n1+n2) & 1)
                return a;

            int b = 0;
            if ( idx1 == n1)
            {
                b = nums2[idx2];
            }
            else if ( idx2 == n2)
            {
                b = nums1[idx1];
            }
            else {
                b = min(nums1[idx1], nums2[idx2]);
            }

            return ( a + b) / 2.0;
        }
    }
    return 0.0;
}
