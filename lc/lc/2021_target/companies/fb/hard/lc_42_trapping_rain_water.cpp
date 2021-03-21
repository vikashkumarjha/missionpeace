/*
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 * */

// https://leetcode.com/problems/trapping-rain-water/
//
//
//
#include "header.hpp"
using namespace std;

int trap(vector<int> &heights) {
    if ( heights.empty() ) return 0;

    int N = heights.size();

    vector<int> leftMax(N, 0);
    vector<int> rightMax(N, 0);

    leftMax[0] = heights[0];
    for ( int i = 1; i < N; i++) {
        leftMax[i] = max(leftMax[i-1], heights[i]);
    }

    rightMax[N-1] = heights[N-1];
    for ( int i = N - 2; i >= 0; i-- ) {
        rightMax[i] = max(rightMax[i+1], heights[i]);
    }

    int waterHold = 0;

    for ( int i = 0; i < N; i++) {
        waterHold += min(leftMax[i], rightMax[i]) - heights[i];
    }

    return waterHold;

}


int main() {

    vector<int> heights = { 0,1,0,2,1,0,1,3,2,1,2,1};
    std::cout << "\n Trapped water:" << trap(heights);
    return 0;

}
