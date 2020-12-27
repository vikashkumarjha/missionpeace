/*
In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if ( grid.empty()) return 0;
        
        vector<vector<int>> DIRS = {{0,1}, {-1,0}, {1,0},{0,-1}};
        
        queue<pair<int,int>> q;
        int R = grid.size();
        int C = grid[0].size();
        
        
        int res = -1;
        int freshOranges = 0;
        for ( int r = 0; r < R; r++) {
            for ( int c = 0; c < C; c++) {
                if ( grid[r][c] == 2) {
                    q.push(make_pair(r,c));
                }else if ( grid[r][c] == 1) {
                    freshOranges++;
                }
            }
        }
        if ( freshOranges == 0) return 0;
        
        while (!q.empty()){
            res++;    
            int qsize = q.size();
            while ( qsize--) {
                auto curr = q.front(); q.pop();
            
                int x = curr.first;
                int y = curr.second;
            
                for (auto d : DIRS) {
                    int x1 =  x + d[0];
                    int y1 =  y + d[1];
                    if ( x1 >= 0 && x1 < R && y1 >=0 && y1 < C) {
                        if ( grid[x1][y1] == 1) {
                            --freshOranges;
                            grid[x1][y1] = 2;
                            q.push({x1,y1});
                        }    
                    }
                
                }
              
            }
        }
       
        
        return ( freshOranges == 0 ? res : -1);
        
        
        
    }
};
