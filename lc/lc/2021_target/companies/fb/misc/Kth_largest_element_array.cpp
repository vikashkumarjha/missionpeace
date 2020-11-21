//
//  Kth_largest_element_array.cpp
//  finishline
//
//  Created by vikash kumar jha on 10/29/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

/*
 Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

 Example 1:

 Input: [3,2,1,5,6,4] and k = 2
 Output: 5
 Example 2:

 Input: [3,2,3,1,2,4,5,5,6] and k = 4
 Output: 4
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// min heap...




int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for ( auto n : nums ){
        pq.push(n);
        if (pq.size() > k) {
            pq.pop();
            		
        }
        
    }
    return pq.top();
    
    
    
}



