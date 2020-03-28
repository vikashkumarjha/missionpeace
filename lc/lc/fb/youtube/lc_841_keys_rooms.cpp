/*
 *
 * There are N rooms and you start in room 0.  Each room has a distinct number
 * in 0, 1, 2, ..., N-1, and each room may have some keys to access the next
 * room.
 *
 * Formally, each room i has a list of keys rooms[i], and each key rooms[i][j]
 * is an integer in [0, 1, ..., N-1] where N = rooms.length.  A key rooms[i][j]
 * = v opens the room with number v.
 *
 * Initially, all the rooms start locked (except for room 0).
 *
 * You can walk back and forth between rooms freely.
 *
 * Return true if and only if you can enter every room.
 *
 * */



#include "header.hpp"
using namespace std;


bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int N = rooms.size();
    vector<bool> isVisited(N, false);
    queue<int> q;

    q.push(0);
    isVisited[0] = true;

    while ( !q.empty()) {
        auto qsize = q.size();
        for ( int i = 0; i < qsize; i++) {
            auto curr = q.front(); q.pop();
            for ( auto x : rooms[curr]) {
                if ( !isVisited[x]) {
                    q.push(x);
                   isVisited[x] = true;
                }
            }
        }

    }

    int visitedRoomsCount = count_if(isVisited.begin(), isVisited.end(), []( auto x ){
            return x == true;
            });

    return ( visitedRoomsCount == N);

}

int main(){
    vector<vector<int>> input1 = {{1,3},{3,0,1},{2},{0}};
    if ( canVisitAllRooms(input1)) {
        std::cout << "\n We can visit all the rooms...";
    }

}



