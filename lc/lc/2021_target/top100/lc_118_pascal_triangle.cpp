#include "../header.hpp"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> result;
        for ( int r = 1; r <= numRows; r++)
        {
                std::vector<int> row(r,1);
                result.push_back(row);
        }
        if ( numRows <= 2 )
                return result;

        for ( int r = 2; r < numRows; r++)
        {
                for ( int e = 1; e < r ; e++)
                {
                        result[r][e] = result[r-1][e-1] + result[r-1][e];
                }
        }
        return result;
        
    }
};
