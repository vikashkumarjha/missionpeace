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