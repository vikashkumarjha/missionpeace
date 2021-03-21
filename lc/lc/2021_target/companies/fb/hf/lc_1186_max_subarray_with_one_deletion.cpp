/*
Given an array of integers, return the maximum sum for a non-empty subarray (contiguous elements) with at most one element deletion. In other words, you want to choose a subarray and optionally delete one element from it so that there is still at least one element left and the sum of the remaining elements is maximum possible.

Note that the subarray needs to be non-empty after deleting one element.

 

Example 1:

Input: arr = [1,-2,0,3]
Output: 4
Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the subarray [1, 0, 3] becomes the maximum value.
Example 2:

Input: arr = [1,-2,-2,3]
Output: 3
Explanation: We just choose [3] and it's the maximum sum.


*/
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> maxforward(arr.size(),arr[0]);
        vector<int> maxskip1(arr.size(),arr[0]);
        for(int i=1; i<n; i++){
            maxforward[i] = max(maxforward[i-1] + arr[i], arr[i]);
            maxskip1[i]   = max(maxskip1[i-1] + arr[i], arr[i]);
            if(i > 1)
                maxskip1[i] = max(maxskip1[i], maxforward[i-2] + arr[i]);
        }
        return *max_element(maxskip1.begin(), maxskip1.end());
        
    }
};


int maximumSum(vector<int>& arr) {
        int n=arr.size();
        vector<int> fw(n,0);
        vector<int> bw(n,0);
        int cur_max=arr[0],max_so_far=arr[0];
        fw[0]=arr[0];
        for(int i=1;i<n;i++){
            cur_max=max(arr[i],cur_max+arr[i]);
            max_so_far=max(max_so_far,cur_max);
            fw[i]=cur_max;
        }
        cur_max=max_so_far=bw[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            cur_max=max(arr[i],cur_max+arr[i]);
            max_so_far=max(max_so_far,cur_max);
            bw[i]=cur_max;
        }
        int res=max_so_far;
        for(int i=1;i<n-1;i++)
            res=max(res,fw[i-1]+bw[i+1]);
        return res;
    }