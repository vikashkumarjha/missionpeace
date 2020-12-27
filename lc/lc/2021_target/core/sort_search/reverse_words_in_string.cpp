#include "header.hpp"

class Solution {
public:
    string reverseWords(string s) {
            int l = 0;
            int r = s.size() - 1;

            reverse(s.begin(), s.end());
            int pos = 0;
            for (  int i = 0; i <= r; i++) {
                if ( s[i] == ' ') {
                    reverse(s.begin() + pos, s.begin() + i);
                    pos = i + 1;
                }
            }
            reverse(s.begin()+pos , s.end());
            return s;
    }
};



int main() {
    Solution sol;
    string r = sol.reverseWords("the sky is     blue");
    cout << "\n The value of the result:" << r;
    return 0;

}



class Solution2 {
public:
    string reverseWords(string s) {
    int start = 0;
    int end = s.size() - 1;
    int i;
    //remove the preceding spaces...
    for (  i = 0; i < s.size() && s[i] == ' ' ; i++){
    }
    start = i;

    // remove the trailing space

    for ( i = s.size() - 1; i >= 0 && s[i] == ' ' ; i--){

    }
    end = i;
    int len = 0;


    // remove the multiple spaces between words..

    for ( int i = start; i <= end; i++){
        if ( s[i] == ' ' && s[i-1] == ' '){
            continue;
        }
        s[len++] = s[i];
     }
    s.erase(s.begin()+len, s.end());
    reverse(s.begin(), s.end());
    start = 0;
    for (int i = 0 ; i < s.size(); i++){
        if ( s[i] == ' '){
            reverse(s.begin() + start, s.begin()+ i );
            start = i + 1;
       }
    }
    reverse(s.begin() + start , s.end());

    
    return s;
        
        
    }
};