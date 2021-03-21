/*

A conveyor belt has packages that must be shipped from one port to another within D days.

The i-th package on the conveyor belt has a weight of weights[i].  Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within D days.

 

Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], D = 5
Output: 15
Explanation: 
A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

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
    
    bool helper(vector<int> &weights, int capacity, int D) {
        int d = 1, currWeight = 0;
        for ( auto w : weights) {
            if (currWeight + w <= capacity) {
                currWeight = currWeight + w;
            }else {
                d++;
                currWeight = w;
            }
        }
        
        return d <= D;
        
    }
    
    
    int shipWithinDays(vector<int>& weights, int D) {
        
        int minCap = *max_element(begin(weights), end(weights));
        int totalCapacity = std::accumulate(begin(weights), end(weights), 0);
        
        int l = minCap;
        int h = totalCapacity;
        
        while ( l <= h) {
            int m = l + ( h - l) / 2;
            
            if ( helper(weights, m , D )) {
                h = m -1;
            }else {
                l = m + 1;
            }
        }
        return l;
    }
};