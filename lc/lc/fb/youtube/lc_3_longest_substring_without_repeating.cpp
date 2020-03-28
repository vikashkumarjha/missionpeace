#include "header.hpp"
using namespace std;


int lengthOfLongestSubstring(string s) {
    int l = 0;
    int r = 0;
    unordered_map<char,int> m;
    int maxLen = 1;

    for ( ;r < s.length(); r++) {
        if ( m.count(s[r])) {
            l = max(l,m[s[r]]);
        }

        maxLen = max(maxLen, r - l + 1);
        m[s[r]] = r + 1;
    }

    return maxLen;
}

int main() {
    std::string s = "abcabcbb";
    int r = lengthOfLongestSubstring(s);
    std::cout << "\n The result:" << r;
    return 0;


}
