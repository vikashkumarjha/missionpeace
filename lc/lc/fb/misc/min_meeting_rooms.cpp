//
//  min_meeting_rooms.cpp
//  finishline
//
//  Created by vikash kumar jha on 12/5/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

//lets calculate the min meeting rooms...
using namespace std;

//what should be the approach..

// what we need to track min end time...



int minMeetingRooms(vector<vector<int>> intervals) {
    if (intervals.size() == 0)
        return 0;
    
    // what should be the approach...
    // sort the intervals...
    // need to track the min end point...
    // if the incoming start time is greater than or equal to min end point... pop
    // push the min end point...
   
    vector<pair<int,int>> toSort;
    
    for ( auto interval : intervals) {
        toSort.push_back(make_pair(interval[0], interval[1]));
    }
    sort(toSort.begin(), toSort.end(), []( auto &a, auto &b) {
        if ( a.first == b.first ){
            return a.second < b.second;
        }
        
        return a.first < b.second;
        
    });
    
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    pq.push(toSort[0].second);
    
    for ( int k = 1; k < toSort.size(); k++) {
        
        auto currMinEndTime = pq.top();
        if ( toSort[k].first >= currMinEndTime){
            pq.pop();
        }
        
        pq.push(toSort[k].second);
    }
    
    return static_cast<int>(pq.size());
}

int minMeetingRooms3(vector<vector<int>>& intervals)
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

/*
int main() {
    printf("hello");
    
    
}
 */
