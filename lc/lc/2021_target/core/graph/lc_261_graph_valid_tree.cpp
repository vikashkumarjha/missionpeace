/*
Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

Example 1:

Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
Output: true
Example 2:

Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
Output: false

*/

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, false);
        if (hasCycle(g, 0, -1, visited))
            return false;
        
        for (bool v : visited)
            if (!v) return false; 
        
        return true;
    } 
private:
    bool hasCycle(vector<vector<int>>& g, int node, int parent, vector<bool>& visited) {
        if (visited[node]) return true;
        visited[node] = true;
         // If an adjacent is visited and  
        // not parent of current vertex, 
        // then there is a cycle. 
        
        for (auto neigh : g[node]){
            if (neigh != parent && hasCycle(g, neigh, node, visited))
                return true;
        }
        return false;
    }
};