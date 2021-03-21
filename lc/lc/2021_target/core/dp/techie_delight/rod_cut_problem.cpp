#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>
#include <climits>
#include <numeric>

using namespace std;




int rodCut(int n) {
    if ( n <= 1) return n;


    int maxValue = n;

    for ( int i = 1; i <= n; i++) {
        maxValue = max(maxValue, i * rodCut(n-i) );

    }

    return maxValue;


}


int rodCutDP(int n) {
    vector<int> dp(n+1);
    for ( int i = 0; i <= n; i++) {
        dp[i] = i;
    }

    for ( int i = 2; i <=n; i++) {
        for ( int j = 1; j<= i; j++) {
            dp[i] = max(dp[i], j * dp[i-j]);
        }
    }

    return dp[n];


}


int main()
{
    int n = 15;
    cout << "\n The maximum profit::" << rodCut(n);
    cout << "\n The maximum profit::" << rodCutDP(n);

    return 0;


}