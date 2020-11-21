#include "header.hpp"
using namespace std;


 int lengthOfLIS(vector<int>& nums) {
     if ( nums.empty()) return 0;
     int N = nums.size();
     vector<int> DP(N,1);
     for ( int i = 1; i < N; i++) {
         for ( int j = 0; j < i; j++) {
             if ( nums[i] > nums[j]) {
                 DP[i] = max(DP[i], DP[j] + 1);
             }
         }
     }
     return *max_element(DP.begin(), DP.end());


 }
