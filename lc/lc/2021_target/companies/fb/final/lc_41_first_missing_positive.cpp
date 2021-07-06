class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool containsOne = false;

        for ( auto n : nums) {
            if ( n == 1 ) {
                containsOne = true;
                break;
            }
        }

        if ( !containsOne) return 1;

        if ( n == 1) {
            return 2;
        }

        for ( int i = 0; i < n; i++) {
            if ( nums[i] <= 0 || nums[i] > n) {
                nums[i] = 1;
            }
        }

        for (int i = 0; i < n; i++) {
            int idx = abs(nums[i]);
            if ( idx == n) {
                nums[0] = -abs(nums[0]);
            }else {
                nums[idx] = -abs(nums[idx]);
            }


        }
        for ( int i = 1; i < n; i++) {
            if ( nums[i] > 0) {
                return i;
            }
        }
        if ( nums[0] > 0) {
            return n;
        }
        return n + 1;

    }
};
