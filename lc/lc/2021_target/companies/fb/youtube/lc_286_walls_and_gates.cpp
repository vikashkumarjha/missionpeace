/*
 * You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.


Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

*/


class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size(), n = m ? rooms[0].size() : 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!rooms[i][j]) {
                    wallsAndGates(rooms, i, j, -1);
                }
            }
        }
    }
private:
    void wallsAndGates(vector<vector<int>>& rooms, int i, int j, int d) {
        int m = rooms.size(), n = rooms[0].size();
        if (i < 0 || i == m || j < 0 || j == n || rooms[i][j] < d + 1) {
            return;
        }
        rooms[i][j] = d + 1;
        wallsAndGates(rooms, i - 1, j, d + 1);
        wallsAndGates(rooms, i + 1, j, d + 1);
        wallsAndGates(rooms, i, j - 1, d + 1);
        wallsAndGates(rooms, i, j + 1, d + 1);
    }
};


class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size(), n = m ? rooms[0].size() : 0;
        vector<vector<int>> DIRS = {{0, 1}, {1, 0}, {-1,0}, {0,-1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!rooms[i][j]) {
                    queue<pair<int, int>> todo;
                    todo.push({i, j});
                    while (!todo.empty()) {
                        pair<int, int> p = todo.front();
                        todo.pop();
                        int r = p.first, c = p.second;
                        for (int k = 0; k < 4; k++) {
                            int x = r + DIRS[k][0];
                            int y = c + DIRS[k][1];
                            if (x >= 0 && x < m && y >= 0 && y < n && rooms[x][y] > rooms[r][c] + 1) {
                                rooms[x][y] = rooms[r][c] + 1;
                                todo.push({x, y});
                            }
                        }
                    }
                }
            }
        }
    }
};
