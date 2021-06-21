
// BFS
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n,0); // 0 uncolored
        
        queue<int> q;
        for ( int i = 0; i < n; i++) {
            if ( colors[i]) continue;
            colors[i]  = 1;
            q.push(i);
            while (!q.empty()) {
                auto x = q.front(); q.pop();
                for ( auto neigh : graph[x]) {
                    if ( !colors[neigh]) {
                        colors[neigh] = -colors[x];
                        q.push(neigh);
                    }
                    else if ( colors[neigh] == colors[x]) 
                    {
                        return false;
                    }
                }
            }
            
        }
        return true;
        
        
        
    }
};


// DFS
class Solution {
public:
    
    bool check(vector<vector<int>> &g, vector<int> &colors, int node, int color) {
        if ( colors[node] != 0) {
            return colors[node] == color;
        }
        
        colors[node] = color;
        for ( auto neigh : g[node]) {
            if (!check(g, colors, neigh, -color)) {
                return false;
            }
        }
        
        return true;
        
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n,0);
        
        for ( int i = 0; i < n; i++) {
            if ( colors[i] == 0 && !check(graph, colors, i, 1)) {
                return false;
            }
            
        }
        return true;
    }
};