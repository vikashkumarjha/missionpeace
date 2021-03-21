/*
 * Given a string containing just the characters '(' and ')', find the length of
 * the longest valid (well-formed) parentheses substring.
 *
 * Example 1:
 *
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 * Example 2:
 *
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 *
 * */

#include "header.hpp"

using namespace std;


/*
 *
 * nstead of finding every possible string and checking its validity, we can
 * make use of stack while scanning the given string to check if the string
 * scanned so far is valid, and also the length of the longest valid string. In
 * order to do so, we start by pushing -1−1 onto the stack.
 *
 * For every \text{‘(’}‘(’ encountered, we push its index onto the stack.
 *
 * For every \text{‘)’}‘)’ encountered, we pop the topmost element and subtract
 * the current element's index from the top element of the stack, which gives
 * the length of the currently encountered valid string of parentheses. If while
 * popping the element, the stack becomes empty, we push the current element's
 * index onto the stack. In this way, we keep on calculating the lengths of the
 * valid substrings, and return the length of the longest valid string at the
 * end.
 *
 * */



int longestValidParentheses(string s) {
    int result = 0;
    if ( s.empty()) return result;
    stack<int> st;
    st.push(-1);

    for ( int i = 0; i < s.length(); i++) {
        if ( s[i] == '(') {
            st.push(i);
        }else {
            st.pop();
            if ( !st.empty()) {
                result = max( result, i - st.top());
            }else {
                st.push(i);
            }

        }



    }

}



public class Solution {
    public int longestValidParentheses(String s) {
            int left = 0, right = 0, maxlength = 0;
            for (int i = 0; i < s.length(); i++) {
                     if (s.charAt(i) == '(') {
                              left++;
                       } else {
                               right++;
                      }
                     if (left == right) {
                             maxlength = Math.max(maxlength, 2 * right);
                     } else if (right >= left) {
                                   left = right = 0;
                     }
             }
             left = right = 0;
             for (int i = s.length() - 1; i >= 0; i--) {
                if (s.charAt(i) == '(') {
                     left++;
                 } else {
                      right++;
                  }
                  if (left == right) {
                          maxlength = Math.max(maxlength, 2 * left);
                  } else if (left >= right) {
                           left = right = 0;
                  }
             }
           return maxlength;
          }
}
