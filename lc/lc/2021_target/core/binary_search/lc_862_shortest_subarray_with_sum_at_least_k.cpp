/*
Return the length of the shortest, non-empty, contiguous subarray of A with sum at least K.

If there is no non-empty subarray with sum at least K, return -1.

 

Example 1:

Input: A = [1], K = 1
Output: 1
Example 2:

Input: A = [1,2], K = 4
Output: -1
Example 3:

Input: A = [2,-1,2], K = 3
Output: 3

*/


class Solution {
public:
   int shortestSubarray(vector<int>& A, int K) {
        
        int n = A.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        
        int sum = 0, res = INT_MAX;
        for (int i = 0; i < n; i++) {
            sum += A[i];
            
            if (sum >= K) res = min(res, i+1);
            while (pq.size() > 0 && sum-pq.top().first >= K) {
                res = min(res, i - pq.top().second);
                pq.pop();
            }
            
            pq.push(make_pair(sum, i));
        }
        
        return res == INT_MAX ? -1 : res;
    }
};