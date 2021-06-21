class Solution {
public:
    int count, n;
    vector<int> f;
    int regionsBySlashes(vector<string>& grid) {
        n = grid.size();
        count = n * n * 4;
        for (int i = 0; i < n * n * 4; ++i)
            f.push_back(i);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0) uni(g(i - 1, j, 2), g(i, j, 0));
                if (j > 0) uni(g(i , j - 1, 1), g(i , j, 3));
                if (grid[i][j] != '/') {
                    uni(g(i , j, 0), g(i , j,  1));
                    uni(g(i , j, 2), g(i , j,  3));
                }
                if (grid[i][j] != '\\') {
                    uni(g(i , j, 0), g(i , j,  3));
                    uni(g(i , j, 2), g(i , j,  1));
                }
            }
        }
        return count;
    }

    int find(int x) {
        if (x != f[x]) {
            f[x] = find(f[x]);
        }
        return f[x];
    }
    void uni(int x, int y) {
        x = find(x); y = find(y);
        if (x != y) {
            f[x] = y;
            count--;
        }
    }
    int g(int i, int j, int k) {
        return (i * n + j) * 4 + k;
    }
};


Split a cell in to 4 parts like this.
We give it a number top is 0, right is 1, bottom is 2 left is 3.

image
(photo by @Sabbi_coder)

Two adjacent parts in different cells are contiguous regions.
In case '/', top and left are contiguous, botton and right are contiguous.
In case '\\', top and right are contiguous, bottom and left are contiguous.
In case ' ', all 4 parts are contiguous.

Congratulation.
Now you have another problem of counting the number of islands.

