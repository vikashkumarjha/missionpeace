/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Implement the NumMatrix class:

NumMatrix(int[][] matrix) initializes the object with the integer matrix matrix.
int sumRegion(int row1, int col1, int row2, int col2) 
returns the sum of the elements of the matrix array inside the 
rectangle defined by its upper left corner (row1, col1) and 
lower right corner (row2, col2).

*/

#include <iostream>
#include <vector>

using namespace std;


class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if ( matrix.empty()) return;

        int R = matrix.size();
        int C = matrix[0].size();
        dp = vector<vector<int>>(R+1, vector<int>(C+1));

        for ( int r = 1; r <= R; r++) {
            for ( int c = 1; c <= C; c++) {
                dp[r][c] = matrix[r-1][c-1] + dp[r-1][c] + dp[r][c-1] - dp[r-1][c-1];
            }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2+1][col2+1] - dp[row2+1][col1] - dp[row1][col2+1] + dp[row1][col1];
        
    }
private:
    vector<vector<int>> dp;

};


