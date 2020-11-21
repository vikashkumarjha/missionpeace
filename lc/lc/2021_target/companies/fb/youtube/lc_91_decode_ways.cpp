//
//  lc_91_decode_ways.cpp
//  lc
//
//  Created by vikash kumar jha on 3/1/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//

/*
 A message containing letters from A-Z is being encoded to numbers using the following mapping:

 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26
 Given a non-empty string containing only digits, determine the total number of ways to decode it.

 Example 1:

 Input: "12"
 Output: 2
 Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 Example 2:

 Input: "226"
 Output: 3
 Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
 */

#if 0

#include "header.hpp"

using namespace std;


int numDecodings(string s) {
    if ( s.empty()) return 0;
    int N = s.size();
    vector<int> DP(N+1, 0);
    DP[0] = 1;
    for ( int i = 1; i <= N; i++) {
        if ( s[i-1] != '0') {
            DP[i] = DP[i-1];
        }
        if ( i >= 2) {
            int v = stoi(s.substr(i-2,2));
            if ( v > 9 && v <= 26) {
                DP[i] += DP[i-2];
            }
        }
        
    }
    
    return DP[N];
    
}

#endif
