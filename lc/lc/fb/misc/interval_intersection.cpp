//
//  interval_intersection.cpp
//  finishline
//
//  Created by vikash kumar jha on 11/26/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

#if 0
#include <stdio.h>
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        std::vector<std::vector<int>> result;
        int i = 0;
        int j = 0;
        while ( i < A.size() && j < B.size())
        {
            int lo = std::max(A[i][0], B[j][0]);
            int hi = std::min(A[i][1] , B[j][1]);
            if ( lo <= hi){
                result.push_back({lo, hi});
            }
            if ( A[i][1] < B[j][1]){
                i++;
            }else {
                j++;
            }
            
            
        }
        return result;
        
        
    }
};

#endif
