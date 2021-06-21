/*
Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.

 

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2
Example 2:

Input: intervals = [[7,10],[2,4]]
Output: 1

*/

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        if ( intervals.size() == 0) {
            return 0;
        }
        
        vector<pair<int,int>> toSort;
        for ( auto x : intervals) {
            toSort.push_back(make_pair(x[0], x[1]));
        }
        
        sort(begin(toSort), end(toSort), []( auto &a, auto &b){
            if ( a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });
        
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(toSort[0].second);
        
        for ( int i = 1; i < toSort.size(); i++) {
            
            auto currStartTime = toSort[i].first;
            auto currEndTime = toSort[i].second;
            int minEndTime = pq.top();
            
            if ( currStartTime >= minEndTime) {
                pq.pop();
                pq.push(currEndTime);
            }else {
                pq.push(currEndTime);
            }
            
        }
        return pq.size();
        
    }
};


class Solution {
public:
    
int minMeetingRooms(vector<vector<int>>& intervals)
{
    int len = intervals.size(); // total len of table should be 2xlen since we have both start and end
    int count = 0, maxCount = 0;
    vector<pair<int, int>> table;
    for(int i=0; i<len; i++)
    {
        // pick up the start, mark with 1
        table.push_back(pair<int, int>(intervals[i][0], 1));
        // pick up the end, mark with -1
        table.push_back(pair<int, int>(intervals[i][1], -1));
    }

    // sort the vector with first - exactly what we need
    sort(table.begin(), table.end());
    for(int i=0; i<table.size(); i++)
    {
        if(table[i].second == 1) count++;
        else count--;
        maxCount = max(count, maxCount);
    }

    return maxCount;
}
};