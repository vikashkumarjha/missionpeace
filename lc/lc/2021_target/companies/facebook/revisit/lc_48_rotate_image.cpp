/***********************************************************
To right rotate, we do following steps.

Find transpose of matrix. Reverse rows of the transpose.

Illustration of above steps :

Let the given matrix be
1   2   3   4
5   6   7   8
9   10  11  12
13  14  15  16

First we find transpose.(Swap Elements Across Diagonal)
1   5   9    13
2   6   10   14
3   7   11   15
4   8   12   16

Then we reverse elements of every row.
13   9   5   1
14   10  6   2
15   11  7   3
16   12  8   4

****************************************************/

class Solution {
public:
   
    void rotate(vector<vector<int>> & M) {
        if (M.empty()) return;
       
        int R = M.size();
        int C = M[0].size();
       
        if (R != C) return;
       
        for (int i = 0; i < R; i++)
            for (int j = 0; j < i; j++)
                swap(M[i][j], M[j][i]);
       
       
        for (int i = 0; i < C; i++)
            reverse(M[i].begin(), M[i].end());    
    }
};

