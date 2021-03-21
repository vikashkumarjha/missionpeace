/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

*/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        int N = nums.size();
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < N - 2; i++)
        {
            if (nums[i] > 0)
                break;
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
            {
                int l = i + 1;
                int r = N - 1;
                int target = 0 - nums[i];

                while (l < r)
                {
                    int currSum = nums[l] + nums[r];
                    if (currSum == target)
                    {
                        res.push_back({nums[i], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[l + 1])
                            l++;
                        while (l < r && nums[r] == nums[r - 1])
                            r--;

                        l++;
                        r--;
                    }
                    else if (currSum > target)
                    {
                        r--;
                    }
                    else
                    {
                        l++;
                    }
                }
            }
        }
        return res;
    }
};