/*

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>

using namespace std;




class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    if (k == 0) return result;
    multiset<int> w;
    for (int i = 0 ; i < nums.size(); i++) {
        if (i >= k)
            w.erase(w.find(nums[i-k]));
        w.insert(nums[i]);
        if (i >= k-1)
            result.push_back(*w.rbegin());
    }
    return result;
        
    }
};


vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    if (k == 0) return result;
    priority_queue<pair<int, int>> w;
    for (int i = 0, n = (int)nums.size(); i < n; i++) {
        while (!w.empty() && w.top().second <= i-k)
            w.pop();
        w.push(make_pair(nums[i],i));
        if (i >= k-1)
            result.push_back(w.top().first);
    }
    return result;
}