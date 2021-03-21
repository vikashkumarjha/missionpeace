#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;



class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> m;
        vector<int> res;
        for ( int i = 0; i < s.length(); i++) {
            m[s[i]] = i;
        }

        int maxPos = 0;
        int offset = -1;
        for ( int i = 0; i < s.length(); i++) {
            maxPos = max(maxPos, m[s[i]]);
            if ( i == maxPos) {
                res.push_back(maxPos - offset);
                offset = i;
            }

        }
        return res;

    }
};


int main()
{
    Solution sol;
    vector<string> input = {"ababcbacadefegdehijhklij"};
    for ( auto s : input) {
        vector<int> o = sol.partitionLabels(s);
        std::for_each(o.begin(), o.end(), [](int x){
            cout << x << " ";
        });

    }


}