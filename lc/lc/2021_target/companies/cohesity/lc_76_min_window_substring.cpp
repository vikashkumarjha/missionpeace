#include <iostream>
#include<string>
#include <unordered_map>
using namespace std;



class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        if ( n2 > n1) return "";
        unordered_map<char,int> mS;
        unordered_map<char,int> mT;

        for ( auto c: t) {
            mT[c]++;
        }
        int startIdx = -1;
        int l = 0;
        int count = 0;
        int res = INT_MAX;

        for ( int r = 0; r < n1; r++) {
            mS[s[r]]++;
            if ( mT.count(s[r]) && mS[s[r]] <= mT[s[r]]) {
                count++;
            }
            // we found the window
            if ( count == n2) {
                while ( (mT.count(s[l]) && mS[s[l]] > mT[s[l]]) ||
                        (!mT.count(s[l]) )) {

                    if ((mT.count(s[l]) && mS[s[l]] > mT[s[l]]) ) {
                        mS[s[l]]--;
                    }
                    l++;
                }
                int winLen = r - l + 1;
                if ( winLen < res) {
                    startIdx = l;
                    res = winLen;
                }
            }
        }

        return ( startIdx == -1 ? "": s.substr(startIdx, res));
    }
};

int main()
{
    Solution s;
    string res = s.minWindow("ADOBECODEBANC", "ABC");
    cout << "\n The result" << res;
    return 0;
}
