//
//  lc_621_task_scheduler.cpp
//  lc
//
//  Created by vikash kumar jha on 2/29/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//
/*
 Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks. Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

 However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

 You need to return the least number of intervals the CPU will take to finish all the given tasks.

  

 Example:

 Input: tasks = ["A","A","A","B","B","B"], n = 2
 Output: 8
 Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 */


#if 0
#include "header.hpp"

using namespace std;






int leastInterval(vector<char>& tasks, int n) {
    if ( tasks.empty()) return 0;
    
    int cycleLength = n + 1;
    int totalDuration = 0;
    
    unordered_map<char,int> m;
    
    for ( auto t : tasks) {
        m[t]++;
    }
    
    priority_queue<int, vector<int>> maxHeap;
    for ( auto x : m) {
        maxHeap.push(x.second);
    }
    
    while ( !maxHeap.empty()) {
        vector<int> tmp;
        int partialCycle = 0;
        for ( int i = 0; i < cycleLength && !maxHeap.empty(); i++ ) {
            auto curr = maxHeap.top(); maxHeap.pop();
            tmp.push_back(curr);
            partialCycle++;
        }
        
        for ( auto t : tmp) {
            if ( --t != 0) {
                maxHeap.push(t);
            }
        }
        if ( !maxHeap.empty()) {
            totalDuration += cycleLength;
        }else {
            totalDuration += partialCycle;
        }
        
     
    }
    return totalDuration;
  
}


int main() {
    vector<char> tasks = {'A','A','A','B','B','B'};
    
    int r = leastInterval(tasks, 2);
    std::cout << "\n The result:" << r;
    
    
}

#endif



