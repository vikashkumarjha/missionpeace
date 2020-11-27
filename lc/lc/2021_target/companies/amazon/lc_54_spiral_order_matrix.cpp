
#include "header.hpp"
class Solution {
public:
    

vector<int> spiralOrder(vector<vector<int>>& matrix) {

    std::vector<int> result;
    int maxRow = matrix.size();

    if ( maxRow == 0)
        return result;

    int maxCol = matrix[0].size();

    int top = 0;
    int bottom = maxRow - 1;
    int left = 0;
    int right = maxCol - 1;


    while ( top <= bottom && left <= right){

        // print the top row..
        for ( int c = left; c <= right; c++){
            result.push_back(matrix[top][c]);
        }


        // print the righmost colum..
        for ( int r = top + 1; r <= bottom; r++ ){
            result.push_back(matrix[r][right]);
        }


        //print the last row...
        if ( top < bottom ){
           for ( int c = right - 1; c >  left; c--){
               result.push_back(matrix[bottom][c]);
           }
        }

        //print the left most column.
        if (left < right){
            for ( int r = bottom; r > top; r--){
                result.push_back(matrix[r][left]);
            }
        }

        top++;
        right--;
        left++;
        bottom--;

    }
    return result;
}



};