/*
 * Given an integer n, return the least number of perfect square numbers that
 * sum to n.
 *
 * A perfect square is an integer that is the square of an integer; in other
 * words, it is the product of some integer with itself. For example, 1, 4, 9,
 * and 16 are perfect squares while 3 and 11 are not.
 *
 *
 *
 *  Example 1:
 *
 *  Input: n = 12
 *  Output: 3
 *  Explanation: 12 = 4 + 4 + 4.
 *  Example 2:
 *
 *  Input: n = 13
 *  Output: 2
 *  Explanation: 13 = 4 + 9.
 *
 *  */


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<int,int> m;
public:
    int numSquares(int n) {
        if ( m.count(n)) {
            return m[n];
        }
        int res = n;
        for ( int i = 1; i * i <= n; i++) {
            res = min( res, 1 + numSquares(n - i*i));
        }
        m[n] = res;
        return res;
    }
};

class Solution {
public:
    int numSquares(int n) {
        unordered_set<int> visited;
        queue<int> q;
        q.push(0);
        visited.insert(0);
        int dist = 1;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int src = q.front(); q.pop();
                for(int i = 1; i * i <= n; i++) {
                    int dest = src + i*i;
                    if(dest == n)
                        return dist;
                    if(dest < n and !visited.count(dest)) {
                        q.push(dest);
                        visited.insert(dest);
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};


class Solution {
public:
    int numSquares(int n) {
        vector<int> DP(n + 1, INT_MAX);
        DP[0] = 0;

        for(int i = 1; i <= n; i++) {
            int m = sqrt(i);

            for (int j = 1; j <= m; j++) {
                if (DP[i - j*j] != INT_MAX)
                    DP[i] = min(DP[i],  DP[i - j*j] + 1);
            }
        }

        return DP[n];
    }
};


int main()
{
    vector<int> input = { 12, 13, 14};
    Solution sol;
    for ( auto x :  input) {
        cout << "\n The result" << sol.numSquares(x);
    }
    return 0;
}
