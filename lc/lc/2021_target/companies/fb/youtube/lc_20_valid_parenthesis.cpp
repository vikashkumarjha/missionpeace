//
//  lc_20_valid_parenthesis.cpp
//  lc
//
//  Created by vikash kumar jha on 2/25/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//
/*
 Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

 An input string is valid if:

 Open brackets must be closed by the same type of brackets.
 Open brackets must be closed in the correct order.
 */

#if 0

#include "header.hpp"
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if ( s.empty())
            return true;
        std::stack<char> st;
        for ( auto c : s) {
            if ( c == '(' || c == '{' || c == '[') {
                st.push(c);
                continue;
            }
            char ch = ' ';
            if ( !st.empty()) {
                ch = st.top(); st.pop();
            }
            switch(c){
                case ')':
                    if ( ch != '(') return false;
                    break;
               case '}':
                    if ( ch != '{') return false;
                    break;
                    
               case ']':
                    if ( ch != '[') return false;
                    break;
                    
               default :
                    return false;
                    
            }
            
        }
        return st.empty();
        
    }
};

#endif









