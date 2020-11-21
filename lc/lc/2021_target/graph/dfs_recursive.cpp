//
//  dfs_recursive.cpp
//  lc
//
//  Created by vikash kumar jha on 2/19/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//


#if 0

// undirected graph.

#include<iostream>
#include<vector>
#include <algorithm>



using namespace std;

typedef pair<int,int> Edge;


class Graph {
private:
    vector<vector<int>> adj;
    int N;
    void helper(vector<bool> &isVisited, int v, vector<int> &result) {
        isVisited[v] = true;
        result.push_back(v);
        for ( auto n : adj[v]) {
            if ( !isVisited[n]) {
                helper(isVisited, n, result);
            }
        }
    }
public:
    Graph(vector<Edge> &edges, int n) {
        N = n;
        adj.resize(N);
        for ( auto &e : edges) {
            adj[e.first].push_back(e.second);
            adj[e.second].push_back(e.first);
        }
    }
    vector<int> doDFS() {
        vector<int> result;
        vector<bool> isVisited(N, false);
        for ( int i = 0; i < N; i++) {
            if ( !isVisited[i]) {
                helper(isVisited, i, result);
            }
        }
        return result;
    }
};


int main() {
    // vector of graph edges as per above diagram
    vector<Edge> edges = {
        // Notice that node 0 is unconnected node
        {1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4},
        {3, 5}, {8, 9}, {8, 12}, {9, 10}, {9, 11}
    };

    // Number of nodes in the graph (0-12)
    int N = 13;

    // create a graph from given edges
    Graph graph(edges, N);
    vector<int> result = graph.doDFS();
    std::for_each(result.begin(), result.end(), [](int x) {
        std::cout << x << "  ";
    });
    return 0;
}


#endif
