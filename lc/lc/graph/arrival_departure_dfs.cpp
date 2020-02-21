//
//  arrival_departure_dfs.cpp
//  lc
//
//  Created by vikash kumar jha on 2/20/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//

#if 0

#include "header.hpp"
using namespace std;


typedef pair<int,int> TimeDetails;
typedef pair<int,int> Edge;

class G{
    
private:
    void helper(int &start, int v, vector<bool> &isVisited) {
        details[v].first = ++start;
        isVisited[v] = true;
        for ( auto n : adj[v]) {
            if ( !isVisited[n]) {
                helper(start, n, isVisited);
            }
        }
        
        
        details[v].second = ++start;
    }
    
public:
    G(vector<Edge> &edges, int n) {
        N = n;
        adj.resize(N);
        details.resize(N);
        for ( const auto &e : edges) {
            adj[e.first].push_back(e.second);
            adj[e.second].push_back(e.first);
        }
        
    }
    
    vector<TimeDetails> dfs() {
        vector<bool> isVisited(N, false);
        int start = -1;
        for ( int i = 0; i < N; i++) {
            if ( !isVisited[i]) {
                helper(start, i , isVisited);
            }
        }
        return details;
        
    }
    
private:
    int N;
    vector<vector<int>> adj;
    vector<TimeDetails> details;
    
};




int main() {
    
    std::cout << "\n Get Arrival and departure time of in DFS \n";
    
    // vector of graph edges as per above diagram
    vector<Edge> edges = {
        {0, 1}, {0, 2}, {2, 3}, {2, 4}, {3, 1}, {3, 5},
        {4, 5}, {6, 7}
    };

    // Number of nodes in the graph
    int N = 8;

    // create a graph from given edges
    G graph(edges, N);
    vector<TimeDetails> details = graph.dfs();
    
    for ( auto &d : details) {
        std::cout << "\n" << d.first << "::" << d.second;
    }
    
    
    return 0;
}

#endif
