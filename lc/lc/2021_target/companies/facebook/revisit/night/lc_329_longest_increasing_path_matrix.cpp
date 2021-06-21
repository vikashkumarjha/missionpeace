class Solution {
public:
    int DFS(vector<vector<int>> & matrix, int i, int j, int prevValue, vector<vector<int>> & grid) {
        int R = matrix.size();
        int C = matrix[0].size();

        if (i < 0 || i >= R|| j < 0 || j >= C)
            return 0;

        if (matrix[i][j] > prevValue) {
            if (grid[i][j] != 0) return grid[i][j];

            int maxPath = 0;

            vector<vector<int>> DIRS = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            for (int k = 0; k < DIRS.size(); k++) {
                int path = DFS(matrix, i + DIRS[k][0], j + DIRS[k][1], matrix[i][j], grid) + 1;
                maxPath  = max(maxPath, path);
            }

            grid[i][j] = maxPath;
            return grid[i][j];
        }

        return 0;
    }

    int longestIncreasingPath(vector<vector<int>> & matrix) {
        if (matrix.empty())  return 0;

        int globalMaxpath = 0;

        int R = matrix.size();
        int C = matrix[0].size();

        vector<vector<int>> grid(R, vector<int>(C, 0));

        for(int i = 0; i< R; i++)
            for(int j = 0; j < C; j++)
                globalMaxpath = max(DFS(matrix, i, j, INT_MIN, grid), globalMaxpath);

        return globalMaxpath;
    }
};
