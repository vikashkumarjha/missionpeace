
// find a point 
// a1 a2 a3 ... a7    A ( i)
// b1 b2 b3     b7    B ( j)
// i + j = ( 7 + 7 + 1 ) / 2



#include "../header.hpp"
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if ( n1 > n2) {
            return findMedianSortedArrays(nums2,nums1);
        }        

        // nums1 is the shorter array


        int halfLen = ( n1 + n2 + 1) / 2;
        int l = 0;
        int r = n1;


        while ( l <= r) {
            int i = (l +  r ) / 2;
            int j = halfLen - i;

            if ( i < r && nums2[j-1] > nums1[i]) {
                l = i + 1;
            }
            else if ( i > l && nums1[i-1] > nums2[j]) {
                r = i - 1;
            }else {

                int x = 0;
                if ( i == 0) {
                    x = nums2[j-1];
                }else if (j == 0) {
                    x = nums1[i-1];
                }else {
                    x = max(nums1[i-1], nums2[j-1]);
                }

                if ( (n1 + n2) & 1 ) {
                    return x;
                }

                int y = 0;
                if ( i == n1) {
                    y = nums2[j];
                }else if (j == n2) {
                    y = nums1[i];
                }else {
                    y = min(nums1[i], nums2[j]);
                }

                return  ( x + y) / 2.0;

            }

        }
        return 0.0;

    }
};