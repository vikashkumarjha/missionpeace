//
//  lc_252_meeting_rooms.cpp
//  lc
//
//  Created by vikash kumar jha on 2/28/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//

#if 0

#include "header.hpp"
using namespace std;


bool canAttendMeetings(vector<vector<int>>& intervals) {
    if ( intervals.empty())
        return true;
    
    
    vector<pair<int,int>> toSort;
    for ( auto a : intervals) {
        toSort.push_back(make_pair(a[0], a[1]));
    }
    
    
    sort(toSort.begin(), toSort.end(), []( auto &a, auto &b) {
        if ( a.first == b.first) return a.second < b.second;
        
        return a.first < b.first;
        
    });
    
    int minEndTime = toSort[0].second;
    for ( int i = 1; i < toSort.size(); i++) {
        if ( minEndTime > toSort[i].first) {
            return false;
        }
        minEndTime = toSort[i].second;
    }
    
    return true;
    
       
}

#endif
