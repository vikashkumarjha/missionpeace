#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Solution {

private:
    pair<int,int> nextMove(int d, int n)
    {
        int quot = (d-1) / n;
        int rem = (d-1) % n;
        int row = n - 1 - quot;
        int col = row % 2 != n % 2 ? rem : n - 1 - rem;
        return {row, col};
    }

public:
    int snakesAndLadders(vector<vector<int>>& board) {
        if ( board.empty()) return 0;
        int R = board.size();
        int C = board[0].size();
        int maxIndex = R * C;

        unordered_map<int,int> dist;
        dist[1] = 0;

        queue<int> q;
        q.push(1);

        while ( !q.empty())
        {
            auto curr = q.front(); q.pop();
            if ( curr == maxIndex ) {
                return dist[curr];
            }

            for ( int k = curr + 1; k <= min(curr + 6, maxIndex); k++)
            {
                pair<int,int> next = nextMove(k,R);

                int r = next.first;
                int c = next.second;

                int nextIndex = ( board[r][c] == -1) ? k : board[r][c];
                if ( !dist.count(nextIndex)) {
                    dist[nextIndex] = dist[curr] + 1;
                    q.push(nextIndex);
                }

            }

        }

        return -1;



    }
};
