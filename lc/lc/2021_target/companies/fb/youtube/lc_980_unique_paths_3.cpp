/*

On a 2-dimensional grid, there are 4 types of squares:

1 represents the starting square.  There is exactly one starting square.
2 represents the ending square.  There is exactly one ending square.
0 represents empty squares we can walk over.
-1 represents obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.


*/


class Solution {
public:
    int dfs(vector<vector<int>>& g, int i, int j, int s, int t_s) {
  if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || g[i][j] < 0 ) return 0;
  if (g[i][j] == 2) 
      return s == t_s ? 1 : 0;
  
  g[i][j] = -2;
   int paths = 0;
   paths += dfs(g, i + 1, j, s + 1, t_s);
   paths += dfs(g, i - 1, j, s + 1, t_s);
   paths += dfs(g, i, j + 1, s + 1, t_s);
   paths += dfs(g, i, j - 1, s + 1, t_s);
  g[i][j] = 0;
  return paths;
}
int uniquePathsIII(vector<vector<int>>& g) {
  auto i1 = 0, j1 = 0, t_steps = 0;
  for (auto i = 0; i < g.size(); ++i)
    for (auto j = 0; j < g[0].size(); ++j) {
      if (g[i][j] == 1) i1 = i, j1 = j;
      if (g[i][j] != -1) ++t_steps;
    }
  return dfs(g, i1, j1, 1, t_steps);
}
};