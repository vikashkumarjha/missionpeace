//
//  snake_ladder_min_throw_required.cpp
//  lc
//
//  Created by vikash kumar jha on 2/20/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//


/*
 * On an N x N board, the numbers from 1 to N*N are written boustrophedonically
 * starting from the bottom left of the board, and alternating direction each
 * row.
 * You start on square 1 of the board (which is always in the last row and first
 * column).  Each move, starting from square x, consists of the following:
 * */


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {

public:
    pair<int, int> nextMove(int d, int n)
    {
        int quot = (d-1) / n;
        int rem = (d-1) % n;
        int row = n - 1 - quot;
        int col = row % 2 != n % 2 ? rem : n - 1 - rem;
        return {row, col};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        if ( board.empty()) return 0;
        int n = board.size();
        int maxIndex= n * n;

        unordered_map<int,int> dist;
        dist.insert(make_pair(1,0));
        queue<int> q;
        q.push(1);

        while (!q.empty()) {
            int curr = q.front(); q.pop();
            if ( curr ==  maxIndex) {
                return dist[curr];
            }

            for ( int k = curr+1; k <= min(curr+6, maxIndex); k++) {
                pair<int,int> next = nextMove(k,n);
                int r = next.first;
                int c = next.second;
                int nextIndex= (board[r][c] == -1) ? k : board[r][c];
                if (!dist.count(nextIndex)) {
                    dist.insert(make_pair(nextIndex, dist[curr] + 1));
                    q.push(nextIndex);
                }
            }

        }
        return -1;

    }
