//
//  find_all_anagrams.cpp
//  finishline
//
//  Created by vikash kumar jha on 2/6/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//

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


#if 0


vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    int w = p.size();
    unordered_map<char,int> hashS;
    unordered_map<char,int> hashP;
    int N = s.size();
    
    for ( int i = 0; i < w; i++) {
        hashS[s[i]]++;
        hashP[p[i]]++;
    }
    if ( hashP == hashS) {
        result.push_back(0);
    }
    
    for ( int r = w; r < s.size(); r++ ) {
        hashS[r - w]--;
        hashS[r]++;
        if (hashS[r-w] == 0 ) {
            hashS.erase(s[r-w]);
        }
        if ( hashS == hashP) {
            result.push_back(r - w +1);
        }
       
    }
    
    return result;
    
    
    
}

#endif  

