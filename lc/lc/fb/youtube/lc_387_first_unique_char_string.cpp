
#if 0
#include "header.hpp"
using namespace std;


int firstUniqChar(string s) {
    if ( s.empty())
        return -1;

    unordered_map<char,int> m;

    for ( auto c : s) {
        m[c]++;
    }

    for ( auto c : s) {
        if ( m[c] == 1) return c;
    }
    return -1;

}

#endif
