//
//  partition_set_into_two_diff_min.cpp
//  lc
//
//  Created by vikash kumar jha on 2/21/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//

#if 0

#include "header.hpp"

using namespace std;




// we are given a set need to divide it into two subset so that diff is min...


int helper(vector<int> &v, int index, int currSum, int totalSum) {
    if ( index == 0) {
        return abs(currSum - ( totalSum - currSum) );
    }
    
    return min ( helper(v, index - 1, currSum + v[index-1], totalSum)
                , helper(v, index - 1, currSum, totalSum));
    
}


int minPartitionDiff(vector<int> &v) {
    int N = v.size();
    
    int totalSum = std::accumulate(v.begin(), v.end(), 0);
    
    return helper(v, N, 0, totalSum );
    
    
}

/*
 The task is to divide the set into two parts.
 We will consider the following factors for dividing it.
 Let
   dp[n+1][sum+1] = {1 if some subset from 1st to i'th has a sum
                       equal to j
                    0 otherwise}
     
     i ranges from {1..n}
     j ranges from {0..(sum of all elements)}

 So
     dp[n+1][sum+1]  will be 1 if
     1) The sum j is achieved including i'th item
     2) The sum j is achieved excluding i'th item.

 Let sum of all the elements be S.

 To find Minimum sum difference, w have to find j such
 that Min{sum - j*2  : dp[n][j]  == 1 }
     where j varies from 0 to sum/2

 The idea is, sum of S1 is j and it should be closest
 to sum/2, i.e., 2*j should be closest to sum.
 */

int minPartitionDiffDP(vector<int> &v) {
    if ( v.empty()) return 0;
    int sum = std::accumulate(v.begin(), v.end() , 0);
    int N = v.size();
    vector<vector<int>> DP(N+1, vector<int>(sum+1, 0));
    // first colume.
    for ( int i = 0; i <= N; i++) {
        DP[i][0] = 1;
    }
    
    
    for ( int i = 1; i <= N; i++) {
        
        for ( int j = 1; j <= sum; j++) {
            DP[i][j] = DP[i-1][j]; // exclude.
            if ( v[i-1] <= j) {
                DP[i][j] |= DP[i][j - v[i-1]];
            }
        }
        
    }
    
    int mid = sum / 2;
    int diff = INT_MAX;
    
    // Find the largest j such that dp[n][j]
    // is true where j loops from sum/2 t0 0
    for (int j=mid; j>=0; j--)
    {
        // Find the
        if (DP[N][j] == true)
        {
            diff = sum-2*j;
            break;
        }
    }
    return diff;
    
   
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    
    int minDiff =  minPartitionDiffDP(v);
    std::cout << "\n The result:" << minDiff;
  
}

#endif





