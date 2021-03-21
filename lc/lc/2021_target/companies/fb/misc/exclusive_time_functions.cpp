//
//  exclusive_time_functions.cpp
//  finishline
//
//  Created by vikash kumar jha on 12/17/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include<stack>
using namespace std;

//Each log is a string with this format: "{function_id}:{"start" | "end"}:{timestamp}"

struct R {
    int id;
    string type;
    int timestamp;
};



vector<int> exclusiveTime(int n, vector<string>& logs) {
    std::stack<R> st;
    std::vector<int> timespent(n,0);
    for ( auto l : logs) {
        stringstream ss(l);
        string token1, token2, token3;
        
        getline(ss, token1, ':');
        getline(ss, token2, ':');
        getline(ss, token3, ':');
        
        struct R r;
        r.id = stoi(token1);
        r.type = token2;
        r.timestamp = stoi(token3);
        
        if ( r.type == "start") {
            st.push(r);
        }else {
            int t = r.timestamp - st.top().timestamp + 1;
            st.pop();
            timespent[r.id] += t;
            if ( !st.empty()) {
                timespent[st.top().id] -= t;
            }
            
            
        }
        return timespent;
        
        
        
        
    }
    return timespent;
    
    
}
