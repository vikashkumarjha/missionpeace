
/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Example 1:

Input: [[0, 30],[5, 10],[15, 20]]
Output: 2
Example 2:

Input: [[7,10],[2,4]]
Output: 1
*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>

using namespace std;


class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {

        if ( intervals.empty()) return 0;

        priority_queue<int,int, greater<int>> pq; // min heap

        vector<pair<int,int>> toSort;

        for (auto i : intervals) {
            toSort.push_back(make_pair(i[0], i[1]));
        }

        sort(begin(toSort), end(toSort), [](auto a, auto b) {
            if ( a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });

        // we will track the min end time 

        pq.push(toSort[0].second);

        


        for ( int i = 1; i < toSort.size(); i++) {
            auto minEndTime = pq.top(); 
            if ( minEndTime <= toSort[i].first) {
                pq.pop();
                pq.push(toSort[i].second);
            }else {
                pq.push(toSort[i].second);
            }

        }

        return pq.size();
    }
};