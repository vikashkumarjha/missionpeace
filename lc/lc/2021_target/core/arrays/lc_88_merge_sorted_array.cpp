/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]

*/


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int writeIdx = m + n - 1;
        int i1 = m - 1;
        int i2 = n -1;
        while ( i1 >= 0 && i2 >= 0) {
            int x1 = nums1[i1];
            int x2 = nums2[i2];
            
            if ( x1 > x2) {
                nums1[writeIdx] = x1;
                i1--;
                writeIdx--;
            }else {
                nums1[writeIdx] = x2;
                i2--;
                writeIdx--;
            }
            
        }
        
        while( i1 >= 0 ) {
            nums1[writeIdx--] = nums1[i1--];
        }
        
        while( i2 >= 0 ) {
            nums1[writeIdx--] = nums2[i2--];
        }
        
        
        
    }
};