//
//  task_scheduler_prac.cpp
//  finishline
//
//  Created by vikash kumar jha on 2/4/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//


#if 0

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <list>
#include <stack>
#include <map>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <numeric>


using namespace std;


 int leastInterval(vector<char>& tasks, int n) {
     
     unordered_map<char,int> hash;
     
     for ( auto t : tasks) {
         hash[t]++;
     }
     
     priority_queue<int> maxHeap;
     for ( auto &it : hash) {
         maxHeap.push(it.second);
     }
     int cycleDuration = n + 1;
     int totalInterval = 0;
     
     while ( !maxHeap.empty()) {
         vector<int> processed;
         int partialCycle = 0;
         for ( int i = 0; i < cycleDuration && !maxHeap.empty(); i++) {
             
             auto tmp = maxHeap.top(); maxHeap.pop();
             processed.push_back(tmp);
             partialCycle++;
         }
         
         for ( auto &job : processed) {
             if ( --job > 0 ) {
                 maxHeap.push(job);
             }
             
         }
         if ( maxHeap.empty())  {
             totalInterval += partialCycle;
         }else {
             totalInterval += cycleDuration;
         }
         
         
     }
     
     return totalInterval;
     
    
 }

#endif



