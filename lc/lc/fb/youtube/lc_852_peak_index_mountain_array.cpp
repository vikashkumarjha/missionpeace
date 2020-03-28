/* Let's call an array A a mountain if the following properties hold:

A.length >= 3
There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].

*/


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
