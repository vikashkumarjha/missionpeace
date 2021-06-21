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