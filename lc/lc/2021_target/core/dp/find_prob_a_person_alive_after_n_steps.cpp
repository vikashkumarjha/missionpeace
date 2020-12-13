/*
Given an island in the form of square matrix and a point inside the matrix where a person is standing. The person is allowed to move one step in any direction (right, left, top, down) on the matrix. Calculate the probability that he is alive after he walks N steps on the island provided that he dies if he steps outside the matrix.

*/

#include <iostream>
#include <map>
#include <string>
using namespace std;
 
#define N 3
 
// Find the probability that person is alive after he walks n steps
// from location (x, y) on the island
float aliveProbability(int x, int y, int n, map<string, float> &dp)
{
    // base case
    if (n == 0)
        return 1.0;
 
    // calculate unique map key from current coordinates(x, y) of person
    // and number of steps(n) left
    string key = to_string(x) + "|" + to_string(y) + "|" + to_string(n);
 
    // if sub-problem is seen for the first time
    if (dp.find(key) == dp.end())
    {
        float p = 0.0;
 
        // move one step up
        if (x > 0)
            p += 0.25 * aliveProbability(x - 1, y, n - 1, dp);
 
        // move one step down
        if (x < N - 1)
            p += 0.25 * aliveProbability(x + 1, y, n - 1, dp);
 
        // move one step left
        if (y > 0)
            p += 0.25 * aliveProbability(x, y - 1, n - 1, dp);
 
        // move one step right
        if (y < N - 1)
            p += 0.25 * aliveProbability(x, y + 1, n - 1, dp);
 
        dp[key] = p;
    }
 
    return dp[key];
}
 
int main()
{
    int n = 3;        // number of steps to be taken
    int x = 0, y = 0; // starting coordinates
 
    // map to store solution to already computed sub-problems
    map<string, float> dp;
 
    // calculate alive Probability
    cout << "Alive probability is " << aliveProbability(x, y, n, dp);
 
    return 0;
}


