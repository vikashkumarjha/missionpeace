/*
Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.

Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.

You may return any answer array that satisfies this condition.

 

Example 1:

Input: [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.


We are motivated (perhaps by the interviewer) to pursue a solution where we modify the original array A in place.

First, it is enough to put all even elements in the correct place, since all odd elements will be in the correct place too. So let's only focus on A[0], A[2], A[4], ...

Ideally, we would like to have some partition where everything to the left is already correct, and everything to the right is undecided.

Indeed, this idea works if we separate it into two slices even = A[0], A[2], A[4], ... and odd = A[1], A[3], A[5], .... Our invariant will be that everything less than i in the even slice is correct, and everything less than j in the odd slice is correct.

Algorithm

For each even i, let's make A[i] even. To do it, we will draft an element from the odd slice. We pass j through the odd slice until we find an even element, then swap. Our invariant is maintained, so the algorithm is correct.
*/



class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int j = 1;
        for (int i = 0; i < A.size(); i += 2)
            if (A[i] % 2 == 1) {
                while (A[j] % 2 == 1)
                    j += 2;

                swap(A[i], A[j]);
            }

        return A;
        
    }
};