/*
 * Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.



Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping

*/

#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<pair<int,int>> toSort;
        for ( auto x : intervals) {
            toSort.push_back(make_pair(x[0], x[1]));
        }

        vector<vector<int>> res;
        if ( intervals.empty()) return res;

        sort(begin(toSort), end(toSort), []( auto a, auto b) {
                if ( a.first == b.first) {
                    return a.second < b.second;
                }

                return a.first < b.first;
        });

        res.push_back({toSort[0].first, toSort[0].second});

        for ( int i = 1; i < toSort.size(); i++)
        {
                int x1 = toSort[i].first;
                int y1 = toSort[i].second;

                if ( x1 > res.back()[1]) {
                    res.push_back({x1, y1});
                    continue;
                }

                // merge it now..
                res.back()[1] = max(res.back()[1], y1);

        }
        return res;
    }
};
