/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).

*/

/*******************************************
12 63421
1
12
 
126 3421
    
12 6
1 2 6
1 26    
*********************************************/
class Solution {
public:
    int numDecodings(string s) {
         if (s.empty() || s[0] == '0')
            return 0;
       
        int N = s.size();
        vector<int> DP(N + 1, 0);
        
        DP[0] = 1;
        
        // Here we are filling DP Table for given String Input
        //   string i - 1 ---> DP[i]
       
        // Here we are filling DP Table for given String Input
        for (int i = 1; i < DP.size(); ++i) {
            if (s[i - 1] != '0')
                DP[i] = DP[i - 1];
           
            if (i >= 2 ) {
                int val = stoi(s.substr(i - 2, 2));
                if ( val > 9 && val <= 26){
                    DP[i] += DP[i - 2];
                }
            }
        }
       
        return DP[N];
        
    }
};