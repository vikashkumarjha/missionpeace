#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;



struct cmp {
    bool operator() (pair<int,string> &a, pair<int,string>  &b) {
        if ( a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};


class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        vector<string> res;
        for ( auto w : words) {
            m[w]++;
        }

        priority_queue<pair<int, string>, vector<pair<int,string>>, cmp> pq;

        for ( auto elem : m) {
            pq.push(make_pair(elem.second, elem.first));
            if ( pq.size() > k ) {
                pq.pop();
            }
        }

        while ( !pq.empty()) {
            auto curr = pq.top(); pq.pop();
            res.insert(res.begin(), curr.second);
        }

        return res;
        
    }
};



