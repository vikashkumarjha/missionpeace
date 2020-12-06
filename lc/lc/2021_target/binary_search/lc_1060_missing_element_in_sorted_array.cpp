
/*

Given a sorted array A of unique numbers, find the K-th missing number starting from the leftmost number of the array.

 

Example 1:

Input: A = [4,7,9,10], K = 1
Output: 5
Explanation: 
The first missing number is 5.
Example 2:

Input: A = [4,7,9,10], K = 3
Output: 8
Explanation: 
The missing numbers are [5,6,8,...], hence the third missing number is 8.

*/


class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        if ( nums.size() == 0 || k == 0)
            return 0;
        
        int prev = nums[0];
        
        for (  int i = 1; i < nums.size(); i++){
            if (( nums[i] - prev ) > 1) {
                k = k - (nums[i]-prev-1);
                if ( k == 0 ){
                    return prev +  (nums[i] - prev -1);
                }else if ( k < 0 ){
                    return prev + ( (nums[i] - prev -1) - std::abs(k) );
                }
            }
            prev = nums[i];
         
        }
        return k > 0 ? prev + k : k;
        
        
    }
};