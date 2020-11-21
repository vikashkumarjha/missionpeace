/*
 * You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Note:
Rotation is not allowed.

Example:

Input: [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).


The problem boils down to a two dimensional version of the longest increasing subsequence problem (LIS).

We must find the longest sequence seq such that the elements in seq[i+1] are greater than the corresponding elements in seq[i] (this means that seq[i] can fit into seq[i+1]).

*/

#include "header.hpp"
using namespace std;

int maxEnvelopes(vector<vector<int>> & e) {

    if ( e.empty() ) return 0;

     std::sort(e.begin(), e.end());

     vector<int> DP(e.size(), 1);

     for ( int i = 0; i < e.size(); i++) {
         for ( int j = 0; j < i; j++) {
             if ( e[j][0] < e[i][0] && e[j][1] < e[i][1] ) {
                 DP[i] = max(DP[i] , DP[j] + 1);
             }
         }
     }

     return *max_element(DP.begin(), DP.end());
}
