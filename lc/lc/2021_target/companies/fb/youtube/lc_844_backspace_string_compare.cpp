#if 0
class Solution {
public:
    bool backspaceCompare(string S, string T) {

        std::stack<char> st1;
        std::stack<char> st2;
        for ( auto c : S){
            if ( c == '#'){

                if ( !st1.empty()) st1.pop();
            }else {
                st1.push(c);
            }
        }
        for ( auto c : T){
            if ( c == '#'){
                if ( !st2.empty())st2.pop();
            }else {
                st2.push(c);
            }
        }
        return ( st1 == st2);


    }
};

#endif
