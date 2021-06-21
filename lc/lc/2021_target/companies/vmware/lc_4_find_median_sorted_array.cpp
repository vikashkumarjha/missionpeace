class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        if ( n1 > n2 ) {
            return findMedianSortedArrays(nums2,nums1);
        }
        
        int halfLen = ( n1 + n2 + 1) / 2;
        int l = 0;
        int r = n1;
        
        while ( l <= r) {
            int index1 = (l +  r ) / 2;
            int index2 = halfLen - index1;

            if ( index1 < r && nums2[index2-1] > nums1[index1]) {
                l = index1 + 1;
               
            }
            else if ( index1 > l && nums1[index1-1] > nums2[index2] ) {
                r = index1 - 1;
            }
            else {
                
                int a = 0;
                if ( index1 == 0) {
                    a = nums2[index2-1];
                }
                else if ( index2 == 0) {
                    a = nums1[index1 -1];
                }
                else {
                    a = max(nums1[index1-1], nums2[index2-1]);
                }
                if ( (n1 + n2) & 1 ) {
                    return a;
                }
                int b = 0;
                if ( index1 == n1) {
                    b = nums2[index2];
                }
                else if ( index2 == n2) {
                    b = nums1[index1];
                }else {
                    b = min(nums1[index1], nums2[index2]);
                }
                return ( a + b) / 2.0;
            }
        }
        return 0.0;
    }
};