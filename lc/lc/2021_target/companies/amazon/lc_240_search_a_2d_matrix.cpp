
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if ( matrix.empty()) return false;
        int R = matrix.size();
        int C = matrix[0].size();
        
        int r = 0;
        int c = C - 1;
        
        while ( r < R && c >= 0) {
            int curr = matrix[r][c];
            if ( curr == target) {
                return true;
            }
            else if ( curr > target) {
                c--;
            }else {
                r++;
            }
        }
        
        return false;
        
    }
};