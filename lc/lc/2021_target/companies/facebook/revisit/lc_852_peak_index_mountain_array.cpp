Let's call an array arr a mountain if the following properties hold:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... arr[i-1] < arr[i]
arr[i] > arr[i+1] > ... > arr[arr.length - 1]
Given an integer array arr that is guaranteed to be a mountain, return any i such that arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        
        int low = 0, high = A.size() - 1;
    while(low < high)
    {
        int mid = low + (high - low)/2;
        if(A[mid] > A[mid+1] && A[mid] > A[mid-1])
            return mid;

        else if(A[mid] < A[mid+1])
                low = mid+1;
        else
            high = mid;
    }
    return -1;
        
    }
};