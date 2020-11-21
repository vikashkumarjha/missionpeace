int minMeetingRooms(vector<vector<int>>& intervals) {
    if ( intervals.size() == 0 ) return 0;

    vector<pair<int,int>> toSort;
    for ( auto interval : intervals) {
        toSort.push_back(make_pair(interval[0], interval[1]));
    }

    sort(toSort.begin(), toSort.end(), [](const pair<int,int> &a, const pair<int,int> &b) {
            if ( a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;

            });


    priroty_queue<int, vector<int>, greater<int>> pq;
    pq.push(toSort[0].second);
    for ( int i = 1; i < toSort.size(); i++) {
        auto currStartTime = toSort[i].first;
        auto currEndTime = toSort[i].second;
        if ( currStartTime >=  pq.top())  {
            pq.pop();
        }
        pq.push(currEndTime);
    }
    return pq.size();

}
