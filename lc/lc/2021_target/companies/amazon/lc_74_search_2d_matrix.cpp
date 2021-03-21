/*


Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.


*/

#include "header.hpp"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if ( matrix.empty()) return false;
        
        int R = matrix.size();
        int C = matrix[0].size();
        int r = 0;
        int c = C - 1;
        
        while ( r < R && c >= 0) {
           
            if ( matrix[r][c] == target) {
                return true;
            }
            
            else if ( matrix[r][c] > target) {
                c--;
            }
            else {
                r++;
            }
            
        }
        
        return false;
        
        
    }
};