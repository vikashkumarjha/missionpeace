 void moveZeroes(vector<int>& nums) {
     int idx = 0;
     for ( auto n : nums) {
         if ( n != 0) {
             nums[idx] = n;
             idx++;
         }
     }
     for ( int i = idx; i < nums.size(); i++) {
         nums[i] = 0;
     }
 }
