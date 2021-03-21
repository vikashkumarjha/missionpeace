/*

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

*/



class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int R = word1.length();
        int C = word2.length();
       
        int dp[R+1][C+1];
        
        for ( int i = 0; i <= R; i++) {
            for ( int j = 0; j <= C; j++) {
                if ( i == 0 ) {
                    dp[i][j] = j;
                }else if ( j == 0 ) {
                    dp[i][j] = i;
                }else if ( word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }else {
                    dp[i][j] = 1 + min(dp[i-1][j-1], 
                                       min(dp[i][j-1], dp[i-1][j]));
                    
                }
                
            }
        }
        return dp[R][C];
       
    }
};


// A Naive recursive C++ program to find minimum number 
// operations to convert str1 to str2 
#include <bits/stdc++.h> 
using namespace std; 
  
// Utility function to find minimum of three numbers 
int min(int x, int y, int z) 
{ 
    return min(min(x, y), z); 
} 
  
int editDist(string str1, string str2, int m, int n) 
{ 
    // If first string is empty, the only option is to 
    // insert all characters of second string into first 
    if (m == 0) 
        return n; 
  
    // If second string is empty, the only option is to 
    // remove all characters of first string 
    if (n == 0) 
        return m; 
  
    // If last characters of two strings are same, nothing 
    // much to do. Ignore last characters and get count for 
    // remaining strings. 
    if (str1[m - 1] == str2[n - 1]) 
        return editDist(str1, str2, m - 1, n - 1); 
  
    // If last characters are not same, consider all three 
    // operations on last character of first string, recursively 
    // compute minimum cost for all three operations and take 
    // minimum of three values. 
    return 1 + min(editDist(str1, str2, m, n - 1), // Insert 
                   editDist(str1, str2, m - 1, n), // Remove 
                   editDist(str1, str2, m - 1, n - 1) // Replace 
                   ); 
} 
  
// Driver program 
int main() 
{ 
    // your code goes here 
    string str1 = "sunday"; 
    string str2 = "saturday"; 
  
    cout << editDist(str1, str2, str1.length(), str2.length()); 
  
    return 0; 
} 