class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // min heap
        priority_queue<int,vector<int>,greater<int>> pq;
        for ( auto n : nums) {
            pq.push(n);
            if ( pq.size() > k){
                pq.pop();
            }
        }
        return pq.top();
   }
};


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++) {
            pq.pop();
        }
        return pq.top();
    }
};


/*
 * The partition subroutine of quicksort can also be used to solve this problem. In partition, we divide the array into

elements>=pivot pivot elements<=pivot
Then, according to the index of pivot, we will know whther the kth largest element is to the left or right of pivot or just itself.

In average, this algorithm reduces the size of the problem by approximately one half after each partition, giving the recurrence T(n) = T(n/2) + O(n) with O(n) being the time for partition. The solution is T(n) = O(n), which means we have found an average linear-time solution. However, in the worst case, the recurrence will become T(n) = T(n - 1) + O(n) and T(n) = O(n^2).


*/


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1, kth;
        while (true) {
            int idx = partition(nums, left, right);
            if (idx == k - 1) {
                kth = nums[idx];
                break;
            }
            if (idx < k - 1) {
                left = idx + 1;
            } else {
                right = idx - 1;
            }
        }
        return kth;
    }
private:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left], l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l++], nums[r--]);
            }
            if (nums[l] >= pivot) {
                l++;
            }
            if (nums[r] <= pivot) {
                r--;
            }
        }
        swap(nums[left], nums[r]);
        return r;
    }
};



