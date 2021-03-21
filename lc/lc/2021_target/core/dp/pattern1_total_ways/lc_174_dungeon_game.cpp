/*
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

 

Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

*/
// Here our goal is to Find way with mininum Health Start
//   -- such that It reaches to Bottom-Right Co-ordinates

class Solution {
private:    
    vector<vector<int>> dp;
   
public:
    // Here we are having recursive Bottom Up Approach
    //  -- grid value is positive -- It increase health
    //  -- grid value is negative -- It decrease health
   
    int f(int i,int j, const vector<vector<int>> & grid){
        int R = grid.size();
        int C = grid[0].size();
       
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        else if(i == R - 1 && j == C - 1)
        {
            return dp[i][j] = max(0, -grid[i][j]);
        }
        else if(i == R - 1)
        {
            return dp[i][j] = max(0, f(i, j + 1, grid) - grid[i][j]);
        }
        else if(j == C - 1)
        {
            return dp[i][j] = max(0, f(i + 1, j, grid) - grid[i][j]);
        }
        else
        {
            return dp[i][j] = max(0, min(f(i + 1, j, grid), f(i, j + 1, grid)) - grid[i][j]);
        }
    }
   
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int R = dungeon.size();
        int C = dungeon[0].size();
       
        dp = vector(R, vector<int>(C, -1));
       
        int ret = f(0, 0, dungeon);
        return ret + 1;
    }
};


class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.empty()) return 0;
        
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>>dp(m+1, vector<int>(n+1, INT_MAX));
        
        dp[m][n-1] = 1; dp[m-1][n] = 1;
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                int need = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                dp[i][j] = (need <= 0) ? 1 : need;
            }
        }
        
        return dp[0][0];
    }
};