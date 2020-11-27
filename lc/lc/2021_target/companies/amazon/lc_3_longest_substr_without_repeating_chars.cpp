
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if ( s.empty()) return 0;
        unordered_map<char,int> m;
        int l = 0;
        int r = 0;
        int res = 0;
        for ( r; r < s.length(); r++) {
            if ( m.count(s[r])) {
                l = max(l, m[s[r]]);
            }
            res = max(res, r - l+1);
           
            m[s[r]] = r+1;
        }
        
        return res;
        
        
        
    }
};