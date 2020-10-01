/*
 * Given an undirected graph, return true if and only if it is bipartite.
 *
 * Recall that a graph is bipartite if we can split it's set of nodes into two
 * independent subsets A and B such that every edge in the graph has one node in
 * A and another node in B.
 *
 * The graph is given in the following form: graph[i] is a list of indexes j for
 * which the edge between nodes i and j exists.  Each node is an integer between
 * 0 and graph.length - 1.  There are no self edges or parallel edges: graph[i]
 * does not contain i, and it doesn't contain any element twice.
 *
 */

// using dfs

class Solution {
public:
    bool isBipartite(vector<vector<int>>& g) {
        int n = g.size();
        vector<int> colors(n,-1);
        for ( int start = 0; start < n; start++) {
            if ( colors[start] == -1) {
                stack<st> st;
                st.push(start);
                colors[start] = 0;
                while ( !st.empty()) {
                    auto node = st.top(); st.pop();
                    for ( auto neigh : g[node]) {
                        if ( colors[neigh] == colors[node]) return false;
                        if ( colors[neigh] == -1) {
                            colors[neigh] = (colors[node] == 0 ? 1 : 0);
                            st.push(neigh);
                        }
                    }
                }
            }
        }

        return true;

    }
};


class SolutionBfs {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int> colors(N, 0);
        // 0 uncolored
        // 1 and 2 are colors
        queue<int> q;
        // any node can be starting poing
        for ( int i = 0; i < N; i++) {
            if (colors[i] == 0) {
                q.push(i);
                colors[i] = 1;
            }

            while ( !q.empty()) {
                auto qsize = q.size();
                while ( qsize--) {
                    auto curr = q.front(); q.pop();
                    auto neigh = graph[curr];
                    for (auto n : neigh) {
                        if (colors[n] == 0) {
                            colors[n] = ( colors[curr] == 1 ? 2 : 1);
                            q.push(n);
                        }
                        else if (colors[n] == colors[curr]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
