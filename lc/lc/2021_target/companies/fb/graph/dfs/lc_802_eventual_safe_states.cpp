/*
In a directed graph, we start at some node and every turn, walk along a directed edge of the graph.  If we reach a node that is terminal (that is, it has no outgoing directed edges), we stop.

Now, say our starting node is eventually safe if and only if we must eventually walk to a terminal node.  More specifically, there exists a natural number K so that for any choice of where to walk, we must have stopped at a terminal node in less than K steps.

Which nodes are eventually safe?  Return them as an array in sorted order.

The directed graph has N nodes with labels 0, 1, ..., N-1, where N is the length of graph.  The graph is given in the following form: graph[i] is a list of labels j such that (i, j) is a directed edge of the graph.

Example:
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Here is a diagram of the above graph.

*/


class Solution {
    
private:
    
    bool treeDFS(vector<vector<int>> &graph, int node, vector<int> &colors) {
        if ( colors[node] != 0 ) {
            // if its black already visited completely then return true
            if ( colors[node] == 2)  return true;
            // if its gray then cycle exits.
            return false;
        }
        
        colors[node] = 1; // gray code
        
        for ( auto n : graph[node] ) {
            if ( colors[n] == 1) return false;
            else if ( colors[n] == 0 ) {
                
                 if (!treeDFS(graph, n, colors) ) {
                     return false;
                 }
            }else {
                continue; // black continue
            }
          
        }
        // everything is visited
        colors[node] = 2;
        return true;
      
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N = graph.size();
        set<int> result;
        vector<int> colors(N, 0); // initially everything white.
        for ( int i = 0; i < graph.size(); i++) {
            if ( treeDFS(graph, i, colors)) {
                result.insert(i);
            } 
            
        }
        vector<int> res(result.begin(), result.end());
        return res;
        
      
    }
};