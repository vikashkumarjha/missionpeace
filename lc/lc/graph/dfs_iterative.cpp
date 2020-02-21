//
//  dfs_iterative.cpp
//  lc
//
//  Created by vikash kumar jha on 2/20/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//

#include<iostream>
#include<vector>
#include <algorithm>
#include <stack>



using namespace std;

typedef pair<int,int> Edge;


// if we want to produce the same result as recursive
// then use the reverse iterator.


#if 0




class Graph {
private:
    vector<vector<int>> adj;
    int N;
    
    
    void helper(int v, vector<bool> &isVisited, vector<int> &result) {
        stack<int> st;
        st.push(v);
        while ( !st.empty()) {
            auto curr = st.top(); st.pop();
            if ( isVisited[curr]) continue;
            isVisited[curr] = true;
            result.push_back(curr);
            
            for ( auto n : adj[curr]) {
                if ( !isVisited[n]) {
                    st.push(n);
                }
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
    
    vector<int> doDFSIter() {
        vector<int> result;
        vector<bool> isVisited(N, false);
        
        for ( int i = 0; i < N; i++) {
            if ( !isVisited[i]) {
                helper(i, isVisited, result);
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
    Graph g(edges, N);
    
    vector<int> result = g.doDFSIter();
    
    std::for_each(result.begin(), result.end(), [](int x) {
        std::cout << x << "  ";
    });
    
    
    

    return 0;
    
    
}

#endif



