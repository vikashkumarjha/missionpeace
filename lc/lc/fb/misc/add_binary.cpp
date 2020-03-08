//
//  add_binary.cpp
//  finishline
//
//  Created by vikash kumar jha on 2/4/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//

//https://leetcode.com/problems/add-binary/

/*
 Given two binary strings, return their sum (also a binary string).

 The input strings are both non-empty and contains only characters 1 or 0.

 Example 1:

 Input: a = "11", b = "1"
 Output: "100"
 Example 2:

 Input: a = "1010", b = "1011"
 Output: "10101"
 */

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
#include <sstream>


using namespace std;



string addBinary(string a, string b) {
    
    stack<char> stA;
    stack<char> stB;
    
    for ( auto c : a) {
        stA.push(c);
    }
    
    for ( auto c : b) {
        stB.push(c);
    }
    int carry = 0;
    stringstream ss;
    
    while ( !stA.empty() || !stB.empty()){
        int x = ( stA.empty()) ? 0 : stA.top() - '0';
        if ( !stA.empty()) stA.pop();
        
        int y = ( stB.empty()) ? 0 : stB.top() - '0';
        if ( !stB.empty()) stB.pop();
        
        
        int sum = x  + y + carry;
        if ( sum == 0) {
            carry = 0;
            ss << '0';
        }else if ( sum == 1) {
            carry = 0;
            ss << '1';
            
        }else if ( sum == 2) {
            carry = 1;
            ss << '0';
           
        }else if ( sum == 3) {
            carry = 1;
            ss << '1';
            
        }
        
        
    }
    if ( carry ) {
        ss << '1';
    }
    
    auto finalStr = ss.str();
    reverse(finalStr.begin(), finalStr.end());
    return finalStr;
    
}

int main() {
    std::cout << "we are in the main...";
    auto s = addBinary("111", "111");
    
    std::cout << "\n The result" << s;
    
    return 0;
}

#endif
