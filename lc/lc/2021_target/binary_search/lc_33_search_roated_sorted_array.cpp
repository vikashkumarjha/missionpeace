
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
#include <sstream>
#include <climits>
#include <cmath>
#include <map>

using namespace std; 

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while ( l < r) {
            int m = l + ( r - l) / 2;
            if ( nums[m] == target) {
                return m;
            }
            else if ( nums[m] < nums[r]) {
                if ( nums[m] < target && target <= nums[r]) {
                    l = m + 1;
                }else {
                    r = m - 1;
                }
            }else if ( nums[m] > nums[r]) {
                if ( nums[m] > target && nums[l] <= target) {
                    r = m - 1;
                }else {
                    l = m + 1;
                }
            }
        }

        if ( nums[l] == target) return l;

        return -1;
        
    }
};
