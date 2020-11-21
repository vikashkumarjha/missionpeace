 int maxSubArrayLen(vector<int>& nums, int k) {
     int maxLen = 0;
     int sum = 0;
     unordered_map<int,int> m;
     for ( int i = 0; i < nums.size(); i++) {
         sum += nums[i];
         if ( sum == k ) {
             maxLen = i + 1;
         }
         if ( m.count(sum - k)) {
             maxLen = max(maxLen, i - m[sum-k]);
         }
         if ( !m.count(sum)) {
             m[sum] = i;
         }

     }
     return maxLen;

 }
