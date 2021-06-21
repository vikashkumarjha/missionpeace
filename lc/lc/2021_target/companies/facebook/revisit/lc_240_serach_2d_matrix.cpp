/*
Write an efficient algorithm that searches for a target value in an m x n integer matrix. The matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int row = matrix.size();
    if (row == 0)
        return false;
    int col = matrix[0].size();

    int i = 0;
    //start with the rightmost col
    int j = col - 1;
    while (i < row && j >= 0)
    {
        if (matrix[i][j] == target)
            return true;
        else if (target > matrix[i][j])
        {
            //increment the row...
            ++i;
        }
        else
            --j;
    }
    return false;
        
    }
};