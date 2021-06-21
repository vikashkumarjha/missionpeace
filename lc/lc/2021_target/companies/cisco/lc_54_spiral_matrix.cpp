// given a m * n matrix return all elements if the matrix in the spiral order
//

#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if ( matrix.size() == 0) return {};
        int R = matrix.size();
        int C = matrix[0].size();

        int top = 0;
        int bottom = R - 1;
        int left = 0;
        int right = C - 1;
        vector<int> result;

        while ( top <= bottom  && left <= right)
        {
            // print the top row
            for ( int c = left; c <= right; c++)
            {
                result.push_back(matrix[top][c]);
            }
            top++;
            for ( int r = top; r <= bottom; r++) {
                result.push_back(matrix[r][right]);
            }
            right--;

            // print the last row
            if ( top <= bottom) {
                for ( int c = right; c >= left; c--) {
                    result.push_back(matrix[bottom][c]);
                }
            }
            bottom--;

            if ( left <= right) {
                for ( int r = bottom; r >= top; r--) {
                    result.push_back(matrix[r][left]);
                }
            }
            left++;
        }

    }
};
