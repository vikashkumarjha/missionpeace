
/*

You are asked to cut off trees in a forest for a golf event. The forest is represented as an m x n map. In this map:

0 means the obstacle can't be reached.
1 represents the ground can be walked through.
A place with a number bigger than 1 represents a tree that can be walked through, and this positive number represents the tree's height.
In one step, you can walk in any of the four directions: top, bottom, left, and right. 
When standing at a point, which is a tree, you can decide whether to cut off the tree.

You are asked to cut off all the trees in this forest in the order of the tree's height - always cut off 
the tree with the lowest height first. When you cut a tree, the value at its cell becomes 1.

You will start from the point (0, 0), return the minimum steps you need to walk to cut off all the trees. If you cannot cut off all the trees, return -1.

You are guaranteed that no two trees have the same height, and there is at least one tree needs to be cut off.

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>

using namespace std;



class Solution {

   private:
    int R, C;
    vector<vector<int>> DIRS = {{0,-1}, {0,1}, {1,0}, {-1,0}};
    bool inBound(int i, int j) { return i>=0 && i<R && j>=0 && j<C; }

    int bfs(vector<vector<int>>& grid, pair<int, int> start, pair<int, int> end) {
        queue<pair<int, int>> q({start});
        vector<vector<int>> visited(R, vector<int>(C, 0));
        visited[start.first][start.second] = 1;
        int dist = 0;
        
        for (; !q.empty(); dist++) {
            auto qsize = q.size();
            while (qsize--) {
                auto curr = q.front(); q.pop();
                if (curr == end) return dist;
                for (int k = 0; k < 4; ++k) {
                    int x= curr.first+DIRS[k][0];
                    int y = curr.second+ DIRS[k][1];
                    if (inBound(x, y) && !visited[x][y] && grid[x][y]) 
                        q.emplace(x, y), visited[x][y] = 1;
                }
               
                
            }
            
        }
        return -1;
    }    
    
public:
    int cutOffTree(vector<vector<int>>& grid) {
        R = grid.size();
        C = R? grid[0].size() : 0;
        if (R == 0 || C == 0) return 0;

        // collect all trees
        vector<pair<int, int>> trees;
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                if (grid[i][j] > 1) trees.emplace_back(i,j);

        // sort trees by height
        sort(trees.begin(), trees.end(), [&](pair<int, int> a, pair<int, int> b) {
            return grid[a.first][a.second] < grid[b.first][b.second];
        });

        // do BFS for each tree
        pair<int, int> start(0, 0);
        int res = 0;
        for (auto& tree : trees) {
            int dist = bfs(grid, start, tree);
            if (dist == -1) return -1;
            res += dist;       
            start = tree;
        }
        return res;        
    }
};