class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int l = 0;
        int r = A.size() - 1;
        while ( l < r ) {
            // even
            if (!(A[l] & 1)) {
                l++;
                continue;
            } 
            
            if (A[r] & 1) {
                r--;
                continue;
            }
            
            swap(A[l++], A[r--]);
        }
        return A;
        
    }
};