class Solution {
private:
    vector<vector<int>> DP;
   
    int maxcoin(int l, int r, vector<int>& nums) {
        if (l > r) return 0;
        if (DP[l][r]) return DP[l][r];
       
        int maxProfit = 0;
        // valid data set [l + 1, r) 
        for(int i = l + 1; i < r; ++i) {
            maxProfit = max(maxProfit, nums[l] * nums[i] * nums[r] + maxcoin(l, i, nums ) + maxcoin(i, r, nums));
        }
       
        DP[l][r] = maxProfit;
        return maxProfit;
    }    
   
   
public:
    int maxCoins(vector<int>& nums) {
        // add 1 at both end so we can burst them.
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
       
        int N = nums.size();
        DP = vector(N , vector<int>(N, 0));
        return maxcoin(0, N - 1, nums);
    }
};