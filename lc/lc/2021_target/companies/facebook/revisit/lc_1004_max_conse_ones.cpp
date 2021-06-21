Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.


class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        
         int start=0,end=0,count=0;
        int max_len=0;
        for(int end=0;end<A.size();++end){
            if(A[end]==0){
                count++;
            }
            while(count>K){
                if(A[start]==0){
                    count--;
                }
                start++;
            }
            max_len=max(max_len,end-start+1);
        }
        
        
       return max_len;
        
    }
};