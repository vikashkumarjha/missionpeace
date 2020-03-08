//
//  min_remove_to_make_valid_parenthesis.cpp
//  finishline
//
//  Created by vikash kumar jha on 2/6/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//


#if 0

string minRemoveToMakeValid(string s) {
    
    stack<char> st;
    for ( auto &c : s) {
        if ( c == '(') {
            st.push(c);
        }else if ( c == ')') {
            if ( !st.empty()) {
                st.pop();
            }else {
                c = '*';
            }
            
        }
        
    }
    
    // Not Useful '(' brace Index's
           while (!st.empty()) {
               s[s.top()] = '*';
               s.pop();
           }
          
           s.erase(remove(s.begin(), s.end(), '*'), str.end());
    
           return str;
    
    
}

#endif
