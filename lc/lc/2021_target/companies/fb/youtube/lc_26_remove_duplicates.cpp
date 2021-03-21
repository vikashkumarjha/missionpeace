//
//  lc_26_remove_duplicates.cpp
//  lc
//
//  Created by vikash kumar jha on 2/29/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//

#if 0

#include "header.hpp"

using namespace std;


int removeDuplicates(vector<int>& nums) {
    if ( nums.empty()) return 0;
    
    int N = nums.size();
    int writeIdx = 1;
    
    for ( int i = 1; i < N; i++) {
        if ( nums[i-1] != nums[i]) {
            nums[writeIdx] = nums[i];
            writeIdx++;
        }
    }
    
    return writeIdx;

}


int main() {
    std::cout << "\n We are in the main.";
    vector<int> n = { 1,1,1,1, 2,3,3,4,5,6};
    int finalSize = removeDuplicates(n);
    for ( int i = 0; i < finalSize; i++) {
        std::cout << n[i] << " ";
    }
    
    
    return 0;
    
}

#endif



