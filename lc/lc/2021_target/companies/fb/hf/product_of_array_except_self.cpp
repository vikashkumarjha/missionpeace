 vector<int> productExceptSelf(vector<int>& nums) {
     int N = nums.size();
     vector<int> left(N,1);
     vector<int> right(N,1);
     vector<int> result(N,1);

     for ( int i = 1; i < N; i++) {
         left[i] = left[i-1] * nums[i-1];
     }
     for ( int i = N - 2; i >= 0; i--) {
         right[i] = right[i+1] * nums[i+1];
     }
     for ( int i = 0; i < N; i++) {
         result[i] = left[i] * right[i];
     }
     return result;

 }
