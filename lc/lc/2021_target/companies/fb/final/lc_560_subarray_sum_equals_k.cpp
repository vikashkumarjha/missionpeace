/*
 * Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.



Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
*/


#include<iostream>
#include <vector>
#include <unordered_map>

using namespace std;




int subarraySum(vector<int>& nums, int k) {
    if ( nums.empty()) return 0;

    int currSum = 0;
    int res = 0;
    unordered_map<int,int> m;

    m[0] = 1;
    for ( int i = 0; i < nums.size(); i++)
    {
        currSum += nums[i];
        if ( m.count(currSum - k))
        {
            res += m[currSum - k];
        }
        m[currSum]++;
    }

    return res;
}


int main()
{
    vector<int> nums= { 1, 2,3};
    int res = subarraySum(nums, 3);
    cout << "\n The result is" << res;
    return 0;
}
