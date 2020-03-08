//
//  task_scheduler.cpp
//  finishline
//
//  Created by vikash kumar jha on 12/13/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>




int minIntervalsRequired(vector<char> &tasks, int n) {
    unordered_map<char, int> hash;
    for ( auto &t : tasks) {
        hash[t]++;
    }
    
    priority_queue<pair<int,char>> pq;
    for ( auto &it : hash) {
        pq.push(make_pair(it.second,it.first));
    }
    
    std::cout << "The queue size" << pq.size() << endl;
    
    int cycle = n + 1;
    int totalTime = 0;
    
    while ( !pq.empty())
    {
        int cycleTime = 0;
        vector<pair<int,char>> tmp;
        for ( int k = 0; k < cycle; k++){
            if ( !pq.empty()){
                tmp.push_back(pq.top());
                pq.pop();
                cycleTime++;
            }
        }
        
        for ( auto t : tmp) {
            if ( --(t.first) != 0) {
                pq.push(t);
                
            }
        }
        
        
        
        totalTime += ( !pq.empty()) ? cycle : cycleTime;
        
    }
    return totalTime;
    
}


int main_tasks()
{
    vector<char> tasks = {'A','A','A','B','B','B'};
    auto result =minIntervalsRequired(tasks,2);
    std::cout << "The total time required..." << result;
    return 0;
    
}
