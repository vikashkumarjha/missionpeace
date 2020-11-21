//
//  merge_intervals.cpp
//  finishline
//
//  Created by vikash kumar jha on 10/31/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

/*
 Given a collection of intervals, merge all overlapping intervals.

 Example 1:

 Input: [[1,3],[2,6],[8,10],[15,18]]
 Output: [[1,6],[8,10],[15,18]]
 Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
 Example 2:

 Input: [[1,4],[4,5]]
 Output: [[1,5]]
 Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 */

//approach...
// we will sort...

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    
    vector<vector<int>> result;
    vector<pair<int,int>> toSort;
    for ( auto val : intervals){
        toSort.push_back(make_pair(val[0], val[1]));
    }
    
    sort(toSort.begin(), toSort.end(), [](auto a, auto b){
        if ( a.first == b.first){
            return a.second < b.second;
        }
        return a.first < b.first;
    });
    
    result.push_back({toSort[0].first, toSort[0].second});
    
    for ( int i = 1; i < toSort.size(); i++){
        
        if ( toSort[i].first <= result.back()[1]){
            // need to merge...
            result.back()[1] = max( toSort[i].second, result.back()[1]);
        }else {
            result.push_back({toSort[i].first, toSort[i].second});
        }
        
    }
    return result;
    
   
}
