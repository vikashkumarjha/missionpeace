/*
Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]


*/




class Solution {
public:
   void reverse(std::vector<int>& v , int begin, int end)
    {
     int last = end - 1;

    while ( begin < last )
     {
        std::swap(v[begin],v[last]);
        ++begin;
        --last;
    }
    }
    
    void rotate(vector<int>& nums, int k) {
        
         if ( k <= 0)
            return;
        int n = nums.size();
        k = k % n;
        reverse(nums,0,n);
        reverse(nums,0,k);
        reverse(nums,k,n);
        
        
    }
};