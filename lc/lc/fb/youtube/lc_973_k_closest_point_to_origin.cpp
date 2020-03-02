//
//  lc_973_k_closest_point_to_origin.cpp
//  lc
//
//  Created by vikash kumar jha on 3/1/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//

#if 0

#include <stdio.h>


vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
        return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
    });
    return vector<vector<int>>(points.begin(), points.begin() + K);
}


#endif
