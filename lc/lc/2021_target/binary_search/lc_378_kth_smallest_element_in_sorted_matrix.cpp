/*

Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.

*/


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



class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
       int R = matrix.size();
    if ( R == 0 ) return INT_MAX;
    
    int C = matrix[0].size();
    int l = matrix[0][0];
    int r = matrix[R-1][C-1];
    
    while ( l <= r) {
        int m = l + ( r - l ) / 2;
        int count = 0;
        for ( int i = 0; i < R; i++) {
            int pos = upper_bound(matrix[i].begin(), matrix[i].end(), m) - matrix[i].begin();
            count += pos;
        }
        if (count < k ) {
            l = m + 1;
        }else {
            r = m - 1;
        }
        
        
    }
    return l;
        
    }
};