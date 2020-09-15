/*
Given a sorted integer array nums, where the range of elements are in the inclusive range [lower, upper], return its missing ranges.

Example:

Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
Output: ["2", "4->49", "51->74", "76->99"]


*/






#include "../header.hpp"




class Solution {
public:
    string get_range(int s, int e) {
        return ( s == e) ? to_string(s) : to_string(s) + "->" + to_string(e);
    }
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
       vector<string> result;
        
        long pre = long(lower)-1;
        long upperLong = upper;
        for(int i =0; i <= nums.size(); i++)
        {
           long cur = (i==nums.size()? upperLong+1:nums[i]);
           if(cur-pre>=2)
            result.push_back(get_range(pre+1,cur-1));
            pre = cur;
        }
        return result;
        
    }
};


int main()
{
    Solution s;
    vector<int> nums = {0,1,3,50,75};
    auto res = s.findMissingRanges(nums, 0, 100);
    for ( auto x : res) {
        cout << x << "\n";
    }
    return 0;
}