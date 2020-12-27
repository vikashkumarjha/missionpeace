/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Example 1:

Input: [[1,1],[2,2],[3,3]]
Output: 3
Explanation:
^
|
|        o
|     o
|  o  
+------------->
0  1  2  3  4
Example 2:

Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
Explanation:
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6

*/

#include "../header.hpp"

class Solution {
public:
    int gcd(int x , int y){
    while ( y ){
        x = x % y;
        swap(x,y);
     }
     return x;
   }


   int maxPoints(vector<vector<int>>& p) {
    int globalMax = 0;
    int N = p.size();

    for ( int i = 0; i < N; i++) {
        unordered_map<string,int> m;
        int dup = 1;
        for ( int j = i + 1; j < N; j++) {
            if ( p[i][0] == p[j][0] && p[i][1] == p[j][1] ) {
                ++dup;
                continue;
            }
            int dx = p[i][0] - p[j][0];
            int dy = p[i][1] - p[j][1];

            int g = gcd(dx, dy);

            m[to_string(dx/g) + "_" + to_string(dy/g)]++;
        }
        int localMax = dup;
        for ( auto e : m) {
            localMax = max(localMax,  e.second + dup);
        }
        globalMax = max(globalMax,localMax);

    }

    return globalMax;

  }
};