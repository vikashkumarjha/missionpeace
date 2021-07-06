
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pos = 0;
        int n = nums.size() - 1;
        int flag = true;
        for ( int i = n; i > 0; i--) {
            if ( nums[i] > nums[i-1]) {
                pos = i - 1;
                flag = false;
                break;
            }
        }

        if ( flag) {
            sort(begin(nums), end(nums));
            return;
        }

        int a = nums[pos];
        int b = nums[pos+1];
        int idx = pos + 1;
        for ( int i = pos + 2; i <= n; i++) {
            if ( nums[i] > a && nums[i] < b) {
                b = nums[i];
                idx = i;
            }
        }
        nums[pos] = b;
        nums[idx] = a;

        sort(nums.begin() + pos + 1, nums.end());


    }
};
