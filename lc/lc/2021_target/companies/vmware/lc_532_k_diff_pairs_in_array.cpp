/*
Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

0 <= i, j < nums.length
i != j
|nums[i] - nums[j]| == k
Notice that |val| denotes the absolute value of val.

 

Example 1:

Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.

*/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int l = 0;
        int r = 1;
        int res = 0;
        
        while ( l < nums.size() && r < nums.size()){
            if ( l == r || (nums[r] - nums[l]) < k ) {
                r++;
            }
            else if ( nums[r] - nums[l] > k) {
                l++;
            }
            else {
                l++;
                res++;
                while ( l < nums.size() && nums[l] == nums[l-1]){
                    l++;
                }
            }
            
        }
        return res;
        
    }
};


class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        if(k < 0) return 0;
        unordered_map<int,int> m;
        for(int i = 0; i < nums.size(); ++i)
           ++m[nums[i]];
        int res = 0;
        if(k != 0) {
            for(auto it = m.begin(); it != m.end(); ++it)
               if(m.find(it->first+k) != m.end())
                   ++res;
        } else {
            for(auto it = m.begin(); it != m.end(); ++it)
               if(it->second > 1)
                   ++res;
        }
        return res;
    
        
    }
};