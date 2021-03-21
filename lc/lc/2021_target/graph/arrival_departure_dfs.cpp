//  arrival_departure_dfs.cpp
//  Created by vikash kumar jha on 2/20/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.

//Given a grap , find the arrival and deplartur time of its vertices in the dfs
//Arrival time is the time at wchich the vertex  is explored first time.
//Departure time is the time when the vertex all negihbors are explored and we
//are ready to backtrack.
// Directed graph
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> Edge;


class Graph {

public:
    int N;
    vector<vector<int>> adj;

    Graph(const vector<Edge> &edges, int n) {
        N = n;
        adj.resize(N);
        for ( auto e : edges) {
            adj[e.first].push_back(e.second);
        }
    }

};

void dfs(Graph &g, int v, vector<pair<int,int>> &details, vector<bool> &isVisited, int &time) {
    details[v].first = ++time;
    isVisited[v] = true;

    for ( int i : g.adj[v]) {
        if ( !isVisited[i]) {
            dfs(g, i, details, isVisited, time);
        }
    }
    details[v].second = ++time;
}

int main()
{
    vector<Edge> edges =  {{0, 1}, {0, 2}, {2, 3}, {2, 4}, {3, 1}, {3, 5},
        {4, 5}, {6, 7} };

    int N = 8;
    Graph g(edges, N);
    // we will do arrival and departure time
    vector<pair<int,int>> details(N);

    vector<bool> isVisited(N,false);
    int startTime = -1;
    for ( int i = 0; i < N; i++) {
        if ( !isVisited[i]) {
            dfs(g, i, details, isVisited, startTime);
        }
    }

    // prin the time details
    for ( int k = 0; k < N; k++) {
        cout << "Node:" << k << " Arrival: " <<  details[k].first << " Departure: " << details[k].second << endl;
    }

    return 0;


}
