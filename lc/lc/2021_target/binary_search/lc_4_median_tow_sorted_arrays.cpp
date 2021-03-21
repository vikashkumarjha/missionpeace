#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <sstream>
#include <climits>
#include <cmath>
#include <map>

using namespace std;  


// a1 a2 a3 ..........am -> i
// b1 b2              bn - j


//i + j = (m + n + 1) /2        left_part          |        right_part
   // A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]
   // B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]


// find a point 
// a1 a2 a3 ... a7    A ( i)
// b1 b2 b3     b7    B ( j)
// i + j = ( 7 + 7 + 1 ) / 2
// find a point 
// a1 a2 a3 ... a7    A ( i)
// b1 b2 b3     b7    B ( j)
// i + j = ( 7 + 7 + 1 ) / 2





class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {

        int m = A.size();
        int n = B.size();

        if ( m > n) {
            return findMedianSortedArrays(B,A);
        }

        // A is the bigger array.
        int l = 0;
        int r = m;
        int halfLen = ( m + n + 1) / 2;

        while ( l <= r) {
            int i = ( l + r) / 2;
            int j = halfLen - i;

            if ( i < r  && B[j-1] > A[i] ) {
                l = i + 1;
            }
            else if ( i > l && A[i-1] > B[j] ) {
                r = i - 1;
            }
            else {
                int a = 0;
                if ( i == 0) {
                    a = B[j - 1];
                }else if ( j == 0) {
                    a = A[i - 1];
                }else {
                    a = max(A[i-1], B[j-1]);
                }

                if ( m + n & 1) {
                    return a;
                }
                int b = 0.0;
                if ( i == m) {
                    b = B[j];
                }else if ( j == n) {
                    b = A[i];
                }else {
                    b = min(A[i], B[j]);
                }

                return ( a + b) / 2.0;
            }
        }

        return 0.0;

    }
};