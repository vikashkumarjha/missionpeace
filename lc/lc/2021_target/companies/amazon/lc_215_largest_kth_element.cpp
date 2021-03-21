// in min heap keep on adding elements and keep the size of heap to k
// so the element at the top will be min which is kth largest.

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq; // min heap
        for ( auto n : nums) {
            pq.push(n);
            if ( pq.size() > k ) {
                pq.pop();
            }
        }
        return pq.top();
        
    }
};