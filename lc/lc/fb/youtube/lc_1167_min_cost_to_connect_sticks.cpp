/*
 * You have some sticks with positive integer lengths.

You can connect any two sticks of lengths X and Y into one stick by paying a cost of X + Y.  You perform this action until there is one stick remaining.

Return the minimum cost of connecting all the given sticks into one stick in this way.



Example 1:

Input: sticks = [2,4,3]
Output: 14
Example 2:

Input: sticks = [1,8,3,5]
Output: 30


*/


class Solution {
public:
    int connectSticks(vector<int>& sticks) {

        priority_queue<int, vector<int>, greater<int>> qu(sticks.begin(),      sticks.end());
        int result = 0;
        while (qu.size() > 1) {
            int a = qu.top(); qu.pop();
            int b = qu.top(); qu.pop();
            result += a + b;
            qu.push(a + b);
        }
        return result;

    }
};
