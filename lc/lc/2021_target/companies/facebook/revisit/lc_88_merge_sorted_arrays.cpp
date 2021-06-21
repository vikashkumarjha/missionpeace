class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int writeIdx = m + n - 1;
        int idx1 = m - 1;
        int idx2 = n - 1;
        
        while ( idx1 >= 0 && idx2 >= 0) {
            if ( nums1[idx1] > nums2[idx2]) {
                nums1[writeIdx] = nums1[idx1];
                idx1--;
                writeIdx--;
            }else {
                nums1[writeIdx] = nums2[idx2];
                idx2--;
                writeIdx--;
            }
            
        }
        
        while ( idx2 >= 0) {
            nums1[writeIdx--] = nums2[idx2--];
        }
        while ( idx1 >= 0) {
            nums1[writeIdx--] = nums1[idx1--];
        }
        
        
    }
};