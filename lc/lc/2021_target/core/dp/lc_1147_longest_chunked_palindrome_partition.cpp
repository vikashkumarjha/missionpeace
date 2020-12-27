/*
Return the largest possible k such that there exists a_1, a_2, ..., a_k such that:

Each a_i is a non-empty string;
Their concatenation a_1 + a_2 + ... + a_k is equal to text;
For all 1 <= i <= k,  a_i = a_{k+1 - i}.
 

Example 1:

Input: text = "ghiabcdefhelloadamhelloabcdefghi"
Output: 7
Explanation: We can split the string on "(ghi)(abcdef)(hello)(adam)(hello)(abcdef)(ghi)".
Example 2:

Input: text = "merchant"
Output: 1
Explanation: We can split the string on "(merchant)".

*/

class Solution {
public:
    int L ;
    vector<vector<int>> DP;
    int solve(int l,int r,string str) {
        if(l>r) return 0;
        if(l == r) return 1;
        if(DP[l][r] != -1) return DP[l][r];
        int ans =1;
        int maxlength = (r-l+1) /2;
            
        for(int i = 0; i < maxlength; i++) {
            bool pos = true;
            for(int j = 0;j <= i;j++) {
                if(str[l+j] != str[r-i+j]) pos = false;
            }
            if(pos) {
                ans = max(ans,solve(l+i+1,r-i-1, str)+2);
                break;
            }
        }
        DP[l][r] = ans;
        return ans;
        
    }
    int longestDecomposition(string str) {
        L = str.length();
        DP = vector(1001, vector<int>(1001, -1));
        return solve(0,L-1, str);
    }
};