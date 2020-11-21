//
//  dfs.cpp
//  lc
//
//  Created by vikash kumar jha on 2/19/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//


#if 0


#include <iostream>
#include <vector>


using namespace std;

typedef pair<int,int> Pair;



class Graph {
private:
    vector<vector<int>> adj;
    int N;
public:
    Graph(vector<Pair> edges, int n) : N(n) {
        adj.resize(N);
        for ( auto e : edges) {
            adj[e.first].push_back(e.second);
        }
        
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    void printGraph() {
        for ( int i = 0; i < N; i++) {
            std::cout << i << ":: ";
            for ( auto n : adj[i]) {
                std::cout << n << " ";
            }
            std::cout << "\n";
        }
        
    }
    
    
    
};





int main() {
    vector<Pair> edges =
    {
        { 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
        { 3, 2 }, { 4, 5 }, { 5, 4 }
    };

    // Number of nodes in the graph
    int N = 6;

    // construct graph
    Graph graph(edges, N);

    // print adjacency list representation of graph
    graph.printGraph();

    return 0;
    
}

#endif
