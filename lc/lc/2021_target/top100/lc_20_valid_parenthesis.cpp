#include "../header.hpp"


class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '['){
                st.push(c);
                continue;
            }
            char stTop = '#';
            if (!st.empty()){
                stTop = st.top();
                st.pop();
            }
            switch(c) {
                case ')':
                if ( stTop != '(') return false;
                break;

                case '}':
                if ( stTop != '{') return false;
                break;

                case ']':
                if ( stTop != '[') return false;
                break;

                default:
                return false;
            }


        }
        return st.empty();
    }
};


int main()
{
    Solution sol;
    vector<string> inputs = {"()", "(())", "{{}}", "(())}"};
    for ( auto s : inputs) {
        if ( sol.isValid(s)) {
            cout<< "\n " << s << "::valid"; 
        }else {
            cout<< "\n " << s << "::in valid"; 
        }    
    }
    return 0;

}
