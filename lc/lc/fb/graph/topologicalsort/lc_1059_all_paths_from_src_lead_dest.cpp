/*
Given the edges of a directed graph, and two nodes source and destination of this graph, determine whether or not all paths starting from source eventually end at destination, that is:

At least one path exists from the source node to the destination node
If a path exists from the source node to a node with no outgoing edges, then that node is equal to destination.
The number of possible paths from source to destination is a finite number.
Return true if and only if all roads from source lead to destination.

*/


class Solution {
public:
   bool dfs(vector<vector<int>> &al, vector<int> &visited, int i, int dest) {
    if (al[i].empty()) return i == dest;
  if (visited[i] != -1) return visited[i];
  visited[i] = 0;
  for (auto j : al[i])
    if (!dfs(al, visited, j, dest)) return false;
  return visited[i] = true;
}
bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
  vector<vector<int>> G(n);
  vector<int> visited(n, -1);
  for (auto e : edges) G[e[0]].push_back(e[1]);
  return dfs(G, visited, source, destination);
}
};