#include "header.hpp"
using namespace std;



int minCost(vector<vector<int>>& costs) {
    if ( costs.empty()) return 0;
    int N = costs.size();

    for ( int i = 1; i < N; i++) {
        costs[i][0] += min( costs[i-1][1], costs[i-1][2]);
        costs[i][1] += min( costs[i-1][0], costs[i-1][2]);
        costs[i][2] += min( costs[i-1][0], costs[i-1][1]);
    }

    return min( costs[N-1][0], min(costs[N-1][1], costs[N-1][1]));
}
