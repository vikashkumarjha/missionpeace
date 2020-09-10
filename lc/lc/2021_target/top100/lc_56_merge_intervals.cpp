/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/

#include "../header.hpp"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<tuple<int,int>> toSort;
        vector<vector<int>> result;

        if ( intervals.size() == 0)
            return result;
        

        for ( auto interval : intervals) {
            toSort.push_back(make_tuple(interval[0], interval[1]));
        }

        sort(toSort.begin(), toSort.end(), [](auto a, auto b){
            if ( get<0>(a) == get<0>(b)) {
                return get<1>(a) < get<1>(b);
            }

            return get<0>(a) < get<0>(b);
        });

        result.push_back({get<0>(toSort[0]), get<1>(toSort[0])});

        for ( int i = 1; i < toSort.size(); i++) {
            // merge condition.
            if ( get<0>(toSort[i]) <= result.back()[1]) {
                result.back()[1] = max(get<1>(toSort[i]), result.back()[1]);
                continue;
            }
            result.push_back({get<0>(toSort[i]), get<1>(toSort[i])});
        }
        return result;
        
    }
};

int main()  
{
    vector<vector<int>> p = {{1,3},{2,6},{8,10},{15,18}};
    Solution s;
    vector<vector<int>> result = s.merge(p);

    for ( auto r : result) {
        std::cout << " [";
        for ( auto c : r) {
            cout << c << " ";
        }
        std::cout << "] ";
    }
    return 0;

}
