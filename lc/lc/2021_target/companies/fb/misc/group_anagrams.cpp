//
//  group_anagrams.cpp
//  finishline
//
//  Created by vikash kumar jha on 10/30/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;




vector<vector<string>> groupAnagrams(vector<string>& strs) {
    
    unordered_map<string, set<string>> m;
    vector<vector<string>> result;
    
    int i = 0;
    for ( auto s : strs){
        std::sort(s.begin(), s.end());
        m[s].insert(strs[i++]);
    }
    for ( auto it : m){
        result.push_back(vector<string>(it.second.begin(), it.second.end()));
    }
    
    return result;
    
    
    
    
}
