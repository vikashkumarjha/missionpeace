 vector<int> maxSlidingWindow(vector<int>& nums, int k) {
     multiset<int> w;
     vector<int> res;
     int N = nums.size();
     for ( int i = 0; i < N; i++) {
         if ( i >= k) {
             w.erase(nums[i-k]);
         }
         w.insert(nums[i]);
         if ( i >= k - 1) {
             res.insert(*w.rbegin());
         }
     }
     return res;
}
