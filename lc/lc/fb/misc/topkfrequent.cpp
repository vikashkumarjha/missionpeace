//
//  topkfrequent.cpp
//  finishline
//
//  Created by vikash kumar jha on 10/29/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

#include <stdio.h>
#include<vector>
#include<unordered_map>
#include <queue>


using namespace std;

//  the approach is


vector<int> topKFrequent(vector<int>& nums, int k) {

    unordered_map<int, int> m;
    for ( auto n : nums ){
        m[n]++;
    }
    vector<pair<int,int>> toSort;
    
    for ( auto it = m.begin(); it != m.end(); it++){
        toSort.push_back(make_pair(it->second, it->first));
    }
    
    std::sort(toSort.begin(), toSort.end(), [](auto &a, auto &b){
        return a.second > b.second;
    });
    
    vector<int> result;
    
    for ( int i = 0; i < k; i++){
        result.push_back(toSort[i].first);
    }
    
    return result;
    
       
}

vector<int> topKFrequent2(vector<int>& nums, int k) {
 std::unordered_map<int,int> m;
    for ( auto n : nums ) {
            m[n]++;
    }
    std::priority_queue<std::pair<int,int>> pq;

    for ( auto it = m.begin(); it != m.end(); it++)
    {
            pq.push(std::make_pair(it->second,it->first));
    }
    int count = 0;
    std::vector<int> result;

    while ( !pq.empty()){
            auto it = pq.top();
            ++count;
            pq.pop();
            result.push_back(it.second);
            if ( count == k ) break;
    }
    return result;
}
