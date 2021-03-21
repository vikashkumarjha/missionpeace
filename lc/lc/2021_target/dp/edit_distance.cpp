//
//  edit_distance.cpp
//  lc
//
//  Created by vikash kumar jha on 2/21/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//


#if 0
#include "header.hpp"
using namespace std;

int helper(string &a, string &b, int n1, int n2) {
    if ( n1 == 0) return n2;
    if ( n2 == 0) return n1;
    
    if ( a[n1-1] == b[n2-1]) {
        return helper( a, b, n1-1, n2-1);
    }else {
        return 1 + min( helper(a, b, n1-1, n2), min(helper(a, b, n1, n2-1), helper(a, b, n1-1, n2-1)));
    }
    
}

// The operation can be permitted insert/remove/replace

int editDistanceRec(string a, string b) {
    
    int n1 = a.length();
    int n2 = b.length();
    
    return  helper(a, b, n1, n2);
    
}


  
int editDistDP(string str1, string str2, int m, int n)
{
    // Create a table to store results of subproblems
    int dp[m + 1][n + 1];
  
    // Fill d[][] in bottom up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // If first string is empty, only option is to
            // insert all characters of second string
            if (i == 0)
                dp[i][j] = j; // Min. operations = j
  
            // If second string is empty, only option is to
            // remove all characters of second string
            else if (j == 0)
                dp[i][j] = i; // Min. operations = i
  
            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
  
            // If the last character is different, consider all
            // possibilities and find the minimum
            else
                dp[i][j] = 1 + min(dp[i][j - 1], // Insert
                                   dp[i - 1][j], // Remove
                                   dp[i - 1][j - 1]); // Replace
        }
    }
  
    return dp[m][n];
}
  

int main() {
     // your code goes here
       string str1 = "sunday";
       string str2 = "saturday";
       std::cout << "\n Edit distance minimum:" << editDistanceRec(str1, str2);
}

#endif









