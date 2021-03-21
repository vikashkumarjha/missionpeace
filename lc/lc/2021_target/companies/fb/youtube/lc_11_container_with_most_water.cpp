//
//  lc_11_container_with_most_water.cpp
//  lc
//
//  Created by vikash kumar jha on 2/28/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//

#if 0
#include "header.hpp"
using namespace std;





int maxArea(vector<int>& h) {
    int area = 0;
    int l = 0;
    int r = h.size() - 1;
    
    while ( l < r) {
        int w = ( r - l);
        int currHeight = min(h[l], h[r]);
        
        area = max(area, w * currHeight);
        
        // as we need to maximize.
        
        if ( h[l] > h[r]) {
            r--;
        }else {
            l++;
        }
      
    }
    
    return area;
    
}


int main() {
    std::cout << "\n We will be solving the max area problem.";
    
    vector<int> heights = {1,8,6,2,5,4,8,3,7};
    std::cout << "\n Max area: " << maxArea(heights);
    
    return 0;
}

#endif



