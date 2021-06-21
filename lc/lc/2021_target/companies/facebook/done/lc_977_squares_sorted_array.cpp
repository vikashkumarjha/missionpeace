
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res;
        int l = 0;
        int r = A.size() - 1;
        
        while ( l <= r) {
            if ( abs(A[l]) > abs(A[r])) {
                res.insert(res.begin(), pow(A[l], 2));   
                l++;
            }else {
                res.insert(res.begin(), pow(A[r], 2));
                r--;
            }
        }
       
        return res;
        
        
    }
};