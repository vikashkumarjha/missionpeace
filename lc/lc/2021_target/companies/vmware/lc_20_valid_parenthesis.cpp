/*
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * An input string is valid if:
 *
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 *
 *
 *  Example 1:
 *
 *  Input: s = "()"
 *  Output: true
 *
 *  */




class Solution {
public:
    bool isValid(string s) {
        if ( s.empty()) return true;

        stack<char> st;
        for ( auto c : s) {
            if ( c == '(' || c == '{' || c == '[')
            {
                st.push(c);
                continue;
            }
            char prev = '#';
            if (!st.empty()) {
                prev = st.top()
                st.pop();
            }
            switch(prev)
            {
                case '('
                    if ( c != ')') return false;
                    break;

                case '{'
                    if ( c != ')') return false;
                    break;

                case '['
                    if ( c != ')') return false;
                    break;
            }
        }
        return st.empty();
    }
};
