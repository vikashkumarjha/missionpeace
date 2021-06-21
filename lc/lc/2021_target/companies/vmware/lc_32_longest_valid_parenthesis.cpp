/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

 

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;


class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        stack<int> st;
        st.push(-1);
        for ( int i = 0; i < s.size(); i++) {
            if ( s[i] == '(') {
                st.push(i);
            }
            else {
                st.pop();
                if ( st.empty()) {
                    st.push(i);                    
                }else {
                    res = max(res, i - st.top());
                }
            }
        }

        return res;
    }
};



class Solution {
public:
    int longestValidParentheses(string s) {
        
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
        for (int i = s.length() - 1; i >= 0; i--) {
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