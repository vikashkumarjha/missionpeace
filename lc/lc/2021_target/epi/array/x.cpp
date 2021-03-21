/********************************************************************
1. Find Cummulative sum for all indexex of Array.
2.  -- Use 2 pointer approach to find L + M, M + L Length chunks previous sums of SubArray
3. Hold Maxinum value of such computation

deal with 2 cases : 
1. {... L ... M ...}
2. {... M ... L ...}
dymanically maintain the sum of M and L by cutting the head and adding the tail


**********************************************************************/
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        if (A.size() < L + M) {
            return 0;
        }

        vector<int> sums = A;
        for (int i = 1; i < A.size(); ++i) {
            sums[i] += sums[i - 1];
        }

        int maxLMSum = sums[L + M - 1];
        int maxLSum = sums[L - 1];
        int maxMSum = sums[M - 1];

        for (int i = L + M; i < A.size(); ++i) {


            maxLSum = max(maxLSum, sums[i - M] - sums[i - L - M]);
            maxMSum = max(maxMSum, sums[i - L] - sums[i - L - M]);

            int singleMax = max(maxLSum + sums[i] - sums[i - M], maxMSum + sums[i] - sums[i - L]);

            maxLMSum = max(maxLMSum, singleMax);
        }

        return maxLMSum;
    }
};
