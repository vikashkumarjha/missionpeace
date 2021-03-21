#include "header.hpp"
using namespace std;

vector<int> findOrder(int N, vector<vector<int>> & pre) {
    vector<int> result;
    vector<int> inDegree(N,0);
    vector<vector<int>> G(N,vector<int>());
    queue<int> q;

    for ( auto p : pre) {
        inDegree[p[0]]++;
        G[p[1]].push_back(p[0]);
    }


    for ( int i = 0; i < N; i++) {
        if ( inDegree[i] == 0) {
            q.push(i);
        }
    }
    while ( !q.empty()) {
        auto node = q.front(); q.pop();
        result.push_back(node);
        for ( auto x : G[node]) {
            inDegree[x]--;
            if ( inDegree[x] == 0 ) {
                q.push(x);
            }
        }
    }

    if ( result.size() == N ) return result;
    return {};

}

int main() {
    vector<vector<int>> pre = {{1,0},{2,0},{3,1},{3,2}};
    vector<int> result = findOrder(4, pre);
    for ( auto c : result) {
        std::cout << c << " ";
    }
    return 0;

}
