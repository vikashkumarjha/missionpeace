/*
 * Remove the minimum number of invalid parentheses in order to make the input
 * string valid. Return all possible results.
 *
 * Note: The input string may contain letters other than the parentheses ( and
 * ).
 *
 * Example 1:
 *
 * Input: "()())()"
 * Output: ["()()()", "(())()"]
 * Example 2:
 *
 * Input: "(a)())()"
 * Output: ["(a)()()", "(a())()"]
 *
 * */

#include "header.hpp"
using namespace std;

// thought process we need to track pairis basically open count
// left parenthesis
// right parenthesis
// we are at what point in the string



void helper(int pair, int index, int remove_left, int remove_right,
        string &s, string sol, unordered_set<string> &result) {

    if ( index == s.length()) {
        if ( pair == 0 && remove_left == 0 && remove_right == 0) {
            result.insert(sol);
        }
    }

    if ( s[index] == '(') {
        // we can exclude and include
        if ( remove_left > 0 ) {
            helper(pair, index + 1, remove_left - 1, remove_right, s, sol, result);
        }

        helper(pair + 1, index + 1, remove_left , remove_right, s, sol + s[index], result);

    }
    else if ( s[index] == ')') {
        // we can exclude and include
        if ( remove_right > 0 ) {
            helper(pair, index + 1, remove_left , remove_right - 1, s, sol, result);
        }
        if ( pair > 0 )
            helper(pair - 1, index + 1, remove_left , remove_right , s, sol + s[index], result);
    }else {
            helper(pair, index + 1, remove_left , remove_right , s, sol + s[index], result);
    }

}



vector<string> removeInvalidParentheses(string s) {
    int remove_left = 0;
    int remove_right = 0;
    int pair = 0;
    unordered_set<string> result;

    for ( int i = 0; i < s.length(); i++) {
        if ( s[i] == '(') {
            remove_left++;
        }else if ( s[i] == ')'){
            if ( remove_left > 0 ) {
                remove_left--;
            }else {
                remove_right++;
            }
        }
    }
    helper(0, 0, remove_left, remove_right, s, "", result);
    return vector<string>(result.begin(), result.end());

}


int main() {
    string s = "()())()";
    vector<string> r = removeInvalidParentheses(s);

    for ( auto x : r) {
        std::cout << x << "   ";
    }

    return 0;

}
