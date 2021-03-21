/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.


*/

//clockwise



#include <iostream>
#include <algorithm>
using namespace std;
 
#define N 4
 
// In-place rotate it by 90 degrees in clockwise direction
void rotateClockwise(int mat[N][N])
{
    // Transpose the matrix
    for (int i = 0; i < N; i++)
        for (int j = 0; j < i; j++)
            swap(mat[i][j], mat[j][i]);
 
    // swap columns
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N/2; j++)
            swap(mat[i][j], mat[i][N - j - 1]);
}


 
// In-place rotate it by 90 degrees in anti-clockwise direction
void rotateAntiClockwise(int mat[N][N])
{
    // Transpose the matrix
    for (int i = 0; i < N; i++)
        for (int j = 0; j < i; j++)
            swap(mat[i][j], mat[j][i]);
 
    // swap rows
    for (int i = 0; i < N/2; i++)
        for (int j = 0; j < N; j++)
            swap(mat[i][j], mat[N - i - 1][j]);
}
 


