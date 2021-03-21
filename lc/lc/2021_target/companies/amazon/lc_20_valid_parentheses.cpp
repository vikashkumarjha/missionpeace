#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if ( s.empty()) return true;

        stack<char> st;
        for ( auto c : s) {
            if ( c == '(' || c == '{' || c == '[') {
                st.push(c);
                continue;
            }
            if ( st.empty()) return false;
            auto popped = st.top(); st.pop();

            switch (popped){
                case '(':
                if ( c != ')') return false;
                break;
                case '{':
                if ( c != '}') return false;
                break;
                case '[':
                if ( c != ']') return false;
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
    vector<string> inputs = {"()", "(){}[]", "(){}[}"};
    Solution sol;
    for ( auto s : inputs) {
        if ( sol.isValid(s)) {
            cout << s << "::" << "valid\n";
        }else {
            cout << s << "::" << "in-valid\n";
        }

    }

    return 0;

}