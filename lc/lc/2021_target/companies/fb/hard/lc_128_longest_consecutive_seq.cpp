/*
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 *
 * Your algorithm should run in O(n) complexity.
 *
 * Example:
 *
 * Input: [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 *
 *
 *
 * */


#include "header.hpp"
using namespace std;




int longestConsecutive(vector<int>& nums) {

    if ( nums.empty() ) return 0;
    sort(nums.begin(), nums.end());
    int result = 1;
    int current = 1;

    for ( int i = 1; i < nums.size(); i++) {
        if ( nums[i] == nums[i-1]) continue;
        if (  nums[i] == nums[i-1] + 1) {
            current+= 1;
        }else {
            result = max(result, current);
            current = 1;
        }
    }
    return result;

}


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if ( nums.size() == 0 ) return 0;
        unordered_set<int> _myset(nums.begin(),nums.end());
        int ans = 1;

        for ( int i = 0; i < nums.size(); i++)
        {
            if ( _myset.find(nums[i] - 1) != _myset.end())
            {
                int j = nums[i];
                while ( _myset.find(j) != _myset.end())
                {
                    j++;
                }
                ans = std::max(ans,j- nums[i] + 1);
            }
        }
        return ans;

    }
};

int main() {
    vector<int> n = {100, 4, 200, 1, 3, 2};
    Solution sol;

    std::cout << "\n Longest consecutive sequence " << longestConsecutive(n);
    std::cout << "\n Longest consecutive sequence " << sol.longestConsecutive(n);
    return 0;

}
