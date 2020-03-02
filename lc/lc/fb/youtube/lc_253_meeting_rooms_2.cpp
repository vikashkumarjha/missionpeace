//
//  lc_253_meeting_rooms_2.cpp
//  lc
//
//  Created by vikash kumar jha on 3/1/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//

/*
 Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

 Example 1:

 Input: [[0, 30],[5, 10],[15, 20]]
 Output: 2
 Example 2:

 Input: [[7,10],[2,4]]
 Output: 1
 */

#if 0

#include "header.hpp"

using namespace std;




// input of the intervals is not sorted.

int minMeetingRooms(vector<vector<int>>& intervals) {
 
    int meetingRooms = 0;
    vector<pair<int,int>> toSort;
    for ( auto i : intervals) {
        toSort.push_back(make_pair(i[0], i[1]));
    }
    
    sort(toSort.begin(), toSort.end(), []( auto &a, auto &b) {
        if ( a.first == b.first ) {
            return a.second < b.second;
        }
        return a.first < b.first;
        
        
    });
    
    // the idea is track the minimum endtime so we need min head.
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    pq.push(toSort[0].second);
    
    for (int i = 1; i < toSort.size(); i++) {
        int minEndTime = pq.top();
        if ( toSort[i].first >= minEndTime) {
            pq.pop();
        }
        
        pq.push(toSort[i].second);
        
    }
    
    return pq.size();
    
}



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


#endif

