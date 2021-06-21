/*
You are given an inclusive range [lower, upper] and a sorted unique integer array nums, where all elements are in the inclusive range.

A number x is considered missing if x is in the range [lower, upper] and x is not in nums.

Return the smallest sorted list of ranges that cover every missing number exactly. That is, no element of nums is in any of the ranges, and each missing number is in one of the ranges.

Each range [a,b] in the list should be output as:
*/


class Solution {
public:
    string get_range(long start, long end)
    {
        return start==end? to_string(start) : to_string(start)+"->"+to_string(end);
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