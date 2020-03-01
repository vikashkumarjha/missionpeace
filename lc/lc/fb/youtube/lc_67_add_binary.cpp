//
//  lc_67_add_binary.cpp
//  lc
//
//  Created by vikash kumar jha on 2/29/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//
#if 0

#include "header.hpp"

using namespace std;



class Solution {
public:
    string addBinary(string a, string b) {
        
        stack<char> stA, stB;
        stringstream ss;
        for ( auto c: a) {
            stA.push(c);
        }
        for ( auto c : b){
            stB.push(c);
        }
        int carry = 0;
        while (!stA.empty() || !stB.empty()){
            auto first = ( !stA.empty()) ? stA.top() - '0' : 0;
            if ( !stA.empty())
                stA.pop();
            auto second = ( !stB.empty()) ? stB.top() - '0': 0;
            if ( !stB.empty())
                stB.pop();
            auto sum = first + second + carry;
            if ( sum == 0 ){
                ss << '0';
                carry = 0;
            }
            else if (sum == 1  ) {
                ss << '1';
                carry = 0;
                
            }else if ( sum == 2){
                carry = 1;
                ss << '0';
            }else if ( sum == 3) {
                carry = 1;
                ss << '1';
            }
            
            
        }
        if ( carry) {
            ss << '1';
        }
        string result = ss.str();
        
        reverse(result.begin(), result.end());
        return result;
       
    }
};


#endif
