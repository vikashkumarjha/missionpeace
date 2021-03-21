class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMin = nums[0];
        int currMax = nums[0];
        int result = nums[0];
        int N = nums.size();
        
        for ( int i = 1; i < N; i++ ) {
            int tmp = currMin;
            currMin = min( nums[i], min(currMax * nums[i] ,  currMin * nums[i]));
            currMax = max( nums[i], max(currMax * nums[i] ,  tmp * nums[i]));
            
            result = max(result, currMax);
        }
        
        return result;
        
        
    }
};