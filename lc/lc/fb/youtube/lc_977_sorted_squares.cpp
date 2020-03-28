/*
 * Given an array of integers A sorted in non-decreasing order, return an array
 * of the squares of each number, also in sorted non-decreasing order.
 *
 * */

#include "header.hpp"
using namespace std;

vector<int> sortedSquares(vector<int>& A) {
    int N = A.size();
    vector<int> B(N);
    int i = 0;
    int j = N - 1;
    int writeIdx = j;
    while ( i <= j) {
        if ( abs(A[i]) > abs(A[j]) ) {
            B[writeIdx--] = A[i] * A[i];
            i++;
        }else {
           B[writeIdx--] = A[j] * A[j];
            j--;
        }
    }

    return B;
}

int main() {
    vector<int> A = { 2,3,4};
    auto R = sortedSquares(A);
    for ( auto x : R) {
        std::cout << x << " ";
    }
}
