#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:

    void dfs(vector<vector<int>> &image, int r, int c, int oldColor, int newColor) {
        vector<vector<int>> DIRS = {{-1,0}, {1,0}, {0,1}, {0,-1}};
        image[r][c] = newColor;
        for ( auto d : DIRS) {
            int x = r + d[0];
            int y = c + d[1];

            if ( x >= 0 && x < image.size() && y >= 0 && y < image.size() && image[x][y] == oldColor) {
                dfs(image, x, y, oldColor, newColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if ( image[sr][sc] != newColor) {
            dfs(image, sr, sc, image[sr][sc], newColor);
        }
    }
};