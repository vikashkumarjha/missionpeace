class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        return bsearch(nums, 0, n-1);
        
    }
    
    int bsearch(vector<int> &nums, int l, int r) {
        if ( l == r )
            return l;
        int m = l + ( r - l)/2;
        if ( nums[m] > nums[m+1]) {
            return bsearch(nums, l, m);
        }
        return bsearch(nums, m+1, r);
    }
};

public class Solution {
    public int findPeakElement(int[] nums) {
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] > nums[i + 1])
                return i;
        }
        return nums.length - 1;
    }
}


public class Solution {
    public int findPeakElement(int[] nums) {
        int l = 0, r = nums.length - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[mid + 1])
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
}