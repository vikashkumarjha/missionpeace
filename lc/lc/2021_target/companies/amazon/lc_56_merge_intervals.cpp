/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

*/

#include "header.hpp"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
    vector<tuple<int,int>> toSort;
    vector<vector<int>> result;
        
    if ( intervals.size() == 0)
        return result;
    
    for ( int i = 0; i < intervals.size(); i++) {
        toSort.push_back(make_tuple(intervals[i][0], intervals[i][1]));
    }
    
    sort(toSort.begin(), toSort.end(), [](auto p1, auto p2){
        if ( get<0>(p1) == get<0>(p2) ) {
            return get<1>(p1) < get<1>(p2);
        }
        return get<0>(p1) < get<0>(p2);
    });
    
    result.push_back({get<0>(toSort[0]), get<1>(toSort[0])});
    
    for ( int i = 1; i < toSort.size(); i++) {
        if ( get<0>(toSort[i])  > result.back()[1]) {
            result.push_back({get<0>(toSort[i]), get<1>(toSort[i])});
            continue;
        }
      result.back()[1] = max(result.back()[1], get<1>(toSort[i]));
        
    }
    return result;
        
        
    }
};