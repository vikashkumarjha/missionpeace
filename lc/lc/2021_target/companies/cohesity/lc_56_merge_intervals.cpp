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
