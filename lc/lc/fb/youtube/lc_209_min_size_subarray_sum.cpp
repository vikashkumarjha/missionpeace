#include "header.hpp"
using namespace std;


int minSubArrayLen(int s, vector<int>& nums) {
    if ( nums.empty()) return 0;
    int l = 0;
    int r = 0;
    int winLen = INT_MAX;
    int winSum = 0;

    for ( ;r < nums.size(); r++) {
        winSum += nums[r];
        if ( winSum >= s) {
            while ( (winSum - nums[l]) >= s) {
                winSum -= nums[l];
                l++;
            }
        }
        winLen = min( winLen , r - l + 1);
    }
    return ( winLen == INT_MAX ? INT_MAX: winLen);
}


int main() {
    vector<int> nums = {2,3,1,2,4,3};
    int s = 7;



}


/*
The above solution may not work if input array contains negative numbers. 
For example arr[] = {- 8, 1, 4, 2, -6}. To handle negative numbers, add a condition to ignore subarrays with negative sums.

*/


// Returns length of smallest subarray with sum greater than x. 
// If there is no subarray with given sum, then returns n+1 
int smallestSubWithSum(int arr[], int n, int x) 
{ 
    // Initialize current sum and minimum length 
    int curr_sum = 0, min_len = n+1; 
  
    // Initialize starting and ending indexes 
    int start = 0, end = 0; 
    while (end < n) 
    { 
        // Keep adding array elements while current sum 
        // is smaller than x 
        while (curr_sum <= x && end < n) 
        { 
            // Ignore subarrays with negative sum if 
            // x is positive. 
            if (curr_sum <= 0 && x > 0) 
            { 
                start = end; 
                curr_sum = 0; 
            } 
  
            curr_sum += arr[end++]; 
        } 
  
        // If current sum becomes greater than x. 
        while (curr_sum > x && start < n) 
        { 
            // Update minimum length if needed 
            if (end - start < min_len) 
                min_len = end - start; 
  
            // remove starting elements 
            curr_sum -= arr[start++]; 
        } 
    } 
    return min_len; 
} 

