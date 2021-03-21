class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int N = nums.size();
        std::sort(nums.begin(), nums.end());
        for ( int i = 0; i < N - 2; i++) {
            if ( i == 0 || (i > 0 && nums[i] != nums[i-1])) {
                int l = i+1;
                int r = N - 1;
                int target = 0 - nums[i];
                
                while ( l < r) {
                    int currSum = nums[l] + nums[r];
                    if ( currSum == target) {
                        res.push_back({nums[i], nums[l], nums[r]});
                        while ( l < r && nums[l] == nums[l+1]) l++;
                        while ( l < r && nums[r] == nums[r-1]) r--;
                        
                        l++;
                        r--;
                      }
                    else if ( currSum > target) {
                        r--;
                    }
                    else{
                        l++;
                    }
                    
                }
           
        }
            
            
            
        }
        return res;
       
    }
};