#include "header.hpp"
using namespace std;


double findMedianSortedArrays(vector<int> &A, vector<int> &B) {

    int m = A.size();
    int n = B.size();

    if ( m > n) {
        return findMedianSortedArrays(B,A);
    }


    // A is the smaller array
    // Now we will try to partion A at the various points

    int left = 0; int right = m; int halfLen = ( m + n + 1) / 2;
    while ( left <= right) {
        int aIndex = ( left + right ) / 2;
        int bIndex = halfLen - aIndex;

        if ( aIndex < right &&  B[bIndex - 1] > A[aIndex]) {
            left = aIndex + 1;
        }
        else if ( aIndex > left && A[aIndex - 1] > B[bIndex]) {
            right = aIndex - 1;
        }else {

            int maxLeft = 0;
            if ( aIndex == 0 ) {
                maxLeft = B[bIndex - 1];
            }else if ( bIndex == 0) {
                maxLeft = A[aIndex - 1];
            }
            else {
                maxLeft = max(A[aIndex-1], B[bIndex - 1]);
            }

            if ( (m + n) % 2 == 1 )
                return maxLeft;


            int minRight = 0;
            if ( aIndex == m ) {
                minRight = B[bIndex];
            }else if ( bIndex == n) {
                minRight = A[aIndex];
            }else {
                minRight = min(B[bIndex], A[aIndex]);
            }

            std::cout << "\n " << maxLeft << "::" << minRight << std::endl;

            return (maxLeft + minRight) / 2.0;

        }

    }
    return 0.0;


}

int main() {
    vector<int> A = { 1, 2};
    vector<int> B = { 3,4};

    std::cout << "\n Median of sorted array:" << findMedianSortedArrays(A, B);
    return 0;
}
