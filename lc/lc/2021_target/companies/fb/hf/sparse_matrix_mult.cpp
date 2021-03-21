class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        if ( A.empty() || B.empty() || A[0].empty() || B[0].empty())
                return vector<vector<int>>();

        int rA = A.size();
        int cA = A[0].size();
        int cB = B[0].size();


        vector<vector<int>> res(rA,vector<int>(cB,0));

        for ( int i = 0; i < rA; i++)
        {
                for ( int j = 0; j < cA; j++)
                {
                        if (A[i][j] == 0 ) {
                                continue;
                        }
                        for ( int k = 0; k < cB; k++)
                                res[i][k] += ( A[i][j] * B[j][k]);
                }
        }

        return res;
        
    }
};