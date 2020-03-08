//
//  edit_distance.cpp
//  finishline
//
//  Created by vikash kumar jha on 10/29/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//
/*
 Input: word1 = "horse", word2 = "ros"
 Output: 3
 Explanation:
 horse -> rorse (replace 'h' with 'r')
 rorse -> rose (remove 'r')
 rose -> ros (remove 'e')
 
 */

#include <iostream>
#include <string>

using namespace std;


int edit_distance(string &s1, string &s2, int m , int n){
    
    if ( m == 0 ){
        return n;
    }
    if ( n == 0){
        return m;
    }
    
    if ( s1[m-1] == s2[n-1]){
        return edit_distance(s1, s2, m-1, n-1);
    }
    
    return 1 + min( edit_distance(s1, s2, m-1, n), min( edit_distance(s1, s2, m , n-1), edit_distance(s1, s2, m-1,n -1)));
    
    
}


int editDistanceDP(string &s1, string &s2 , int m , int n){
    

       int dp[m+1][n+1];


       for ( int i = 0; i <= m; i++){
           for ( int j = 0; j <= n; j++){

               if ( i == 0 ){
                   dp[i][j] = j;
               }
               else if ( j == 0){
                   dp[i][j] = i;
               }
               else if ( s1[i-1] == s2[j-1]){
                   dp[i][j] = dp[i-1][j-1];
               }else {

                   dp[i][j] = 1 +
                           std::min(std::min(dp[i-1][j], dp[i][j-1]) ,
                           dp[i-1][j-1]
                   );
               }
           }
       }

       return dp[m][n];
    
 
    
}


int main_edit_distance()
{
    string s1 = "horse";
    string s2 = "ros";
    
    
    std::cout << "The value of the edit distance " << editDistanceDP(s1, s2, static_cast<int>(s1.length()), static_cast<int>(s2.length()));
    
    return 0;
}

