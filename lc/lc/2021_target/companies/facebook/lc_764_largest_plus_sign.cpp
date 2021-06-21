class Solution {
private:
    bool canExpand(vector<vector<int>>& DP, int N, int x, int y, int k) {
        if (x - k < 0 || y - k < 0 || x + k >= N || y + k >= N)
            return false;
       
        return DP[x - k][y] && DP[x][y + k] && DP[x + k][y] && DP[x][y - k];
    }
   
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> DP(N, vector<int>(N, 1));
       
        for (const auto & m : mines)
             DP[m[0]][m[1]] = 0;
       
        int res = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if ( DP[i][j] == 0) continue; 
               
                int k = 0;
                while (canExpand(DP, N, i, j, k))
                    ++k;
               
                res = max(res, k);
            }
        }
       
        return res;
    }
};