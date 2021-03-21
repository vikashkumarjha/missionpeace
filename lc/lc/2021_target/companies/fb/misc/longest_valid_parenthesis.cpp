//
//  longest_valid_parenthesis.cpp
//  finishline
//
//  Created by vikash kumar jha on 10/30/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(string s){
    std::stack<char> st;
    for ( auto c : s){
        if ( c == '('){
            st.push(c);
        }
        else if ( !st.empty() && st.top() == '('){
            st.pop();
        }
        else
            return false;
        
    }
    return st.empty();
    
    
}



int longestValidParentheses(string s) {
    int result = 0;
    
    for ( int i = 0; i < s.length(); i++){
        for ( int j = i + 2; j <= s.length(); j++){
            if (isValid(s.substr(i, j-i))) {
                result = max(result, j -i);
            }
        }
    }
    return result;
    
    
}

/*
 Approach 3: Using Stack
 Algorithm

 Instead of finding every possible string and checking its validity, we can make use of stack while scanning the given string to check if the string scanned so far is valid, and also the length of the longest valid string. In order to do so, we start by pushing -1−1 onto the stack.

 For every ‘(’ encountered, we push its index onto the stack.

 For every ‘)’ encountered, we pop the topmost element and subtract the current element's index from the top element of the stack, which gives the length of the currently encountered valid string of parentheses. If while popping the element, the stack becomes empty, we push the current element's index onto the stack. In this way, we keep on calculating the lengths of the valid substrings, and return the length of the longest valid string at the end.
 */


int longestValidParentheses2(string s) {
    
     int maxans = 0;
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (st.empty()) {
                st.push(i);
            } else {
                maxans = max(maxans, i - st.top());
            }
        }
    }
    return maxans;
    
}

/*
 In this approach, we make use of two counters leftleft and rightright. First, we start traversing the string from the left towards the right and for every \text{‘(’}‘(’ encountered, we increment the leftleft counter and for every \text{‘)’}‘)’ encountered, we increment the rightright counter. Whenever leftleft becomes equal to rightright, we calculate the length of the current valid string and keep track of maximum length substring found so far. If rightright becomes greater than leftleft we reset leftleft and rightright to 00.

 Next, we start traversing the string from right to left and similar procedure is applied.
 */

class Solution {
public:
    int longestValidParentheses3(string s) {
        
        int left = 0, right = 0, maxlength = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxlength = max(maxlength, 2 * right);
            } else if (right >= left) {
                left = right = 0;
            }
        }
        left = right = 0;
        for (auto i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxlength = max(maxlength, 2 * left);
            } else if (left > right) {
                left = right = 0;
            }
        }
        return maxlength;
    }
};


int main_longest_valid()
{
    std::cout << "we are going to find the longest valid parenthesis...";
    std::cout << "The result:" << longestValidParentheses2("(())");
    return 0;
}
