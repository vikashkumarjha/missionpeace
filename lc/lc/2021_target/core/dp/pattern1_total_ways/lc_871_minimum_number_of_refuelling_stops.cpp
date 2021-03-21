

/*
A car travels from a starting position to a destination which is target miles east of the starting position.

Along the way, there are gas stations.  Each station[i] represents a gas station that is station[i][0] miles east of the starting position, and has station[i][1] liters of gas.

The car starts with an infinite tank of gas, which initially has startFuel liters of fuel in it.  It uses 1 liter of gas per 1 mile that it drives.

When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station into the car.

What is the least number of refueling stops the car must make in order to reach its destination?  If it cannot reach the destination, return -1.

Note that if the car reaches a gas station with 0 fuel left, the car can still refuel there.  If the car reaches the destination with 0 fuel left, it is still considered to have arrived.



Approach 1: 1D DP, O(N^2)
dp[t] means the furthest distance that we can get with t times of refueling.

So for every station s[i],
if the current distance dp[t] >= s[i][0], we can refuel:
dp[t + 1] = max(dp[t + 1], dp[t] + s[i][1])

In the end, we'll return the first t with dp[t] >= target,
otherwise we'll return -1.

*/

#include "../../header.hpp"



    int minRefuelStops(int target, int startFuel, vector<vector<int>> s) {
        long dp[501] = {startFuel};
        for (int i = 0; i < s.size(); ++i)
            for (int t = i; t >= 0 && dp[t] >= s[i][0]; --t)
                dp[t + 1] = max(dp[t + 1], dp[t] + s[i][1]);
        for (int t = 0; t <= s.size(); ++t)
            if (dp[t] >= target) return t;
        return -1;
    }


/*

i is the index of next stops to refuel.
res is the times that we have refeuled.
pq is a priority queue that we store all available gas.

We initial res = 0 and in every loop:

We add all reachable stop to priority queue.
We pop out the largest gas from pq and refeul once.
If we can't refuel, means that we can not go forward and return -1
C++:


*/


    int minRefuelStops(int target, int cur, vector<vector<int>> s) {
        int i = 0, res;
        priority_queue<int>pq;
        for (res = 0; cur < target; res++) {
            while (i < s.size() && s[i][0] <= cur)
                pq.push(s[i++][1]);
            if (pq.empty()) return -1;
            cur += pq.top(), pq.pop();
        }
        return res;
    }


