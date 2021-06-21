class Solution {
public:
    vector<int> pancakeSort(vector<int> A) {
        vector<int> result;
        int n = A.size();
        
        while(n) {
            int i = 0;
            while (i < n) {
               if (A[i] == n)
                   break;
               i++;
            }
            
            // Indexing is 0....N - 1
            // Numbers are 1....N
            reverse(A.begin(), A.begin() + i + 1);
            result.push_back(i + 1);   // Put Largest Element to first place
            
            reverse(A.begin(), A.begin() + n);
            result.push_back(n);       // Reverse Part - 2 ... Put Largest Element at Back Appriapiate Place
            
            n--;
        }
        
        return result;
    }
};


Find the index i of the next maximum number x.
Reverse i + 1 numbers, so that the x will be at A[0]
Reverse x numbers, so that x will be at A[x - 1].
Repeat this process N times.

 vector<int> pancakeSort(vector<int> A) {
        vector<int> res;
        int x,i;
        for (x = A.size(); x > 0; --x) {
            for (i = 0; A[i] != x; ++i);
            reverse(A.begin(), A.begin() + i + 1);
            res.push_back(i + 1);
            reverse(A.begin(), A.begin() + x);
            res.push_back(x);
        }
        return res;
    }