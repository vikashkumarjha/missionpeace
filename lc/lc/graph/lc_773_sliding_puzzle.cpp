/*

On a 2x3 board, there are 5 tiles represented by the integers 1 through 5, and an empty square represented by 0.

A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.

The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

Given a puzzle board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.

Examples:

Input: board = [[1,2,3],[4,0,5]]
Output: 1
Explanation: Swap the 0 and the 5 in one move.
Input: board = [[1,2,3],[5,4,0]]
Output: -1
Explanation: No number of moves will make the board solved.





Example "graph":
The nodes are comprised of each candidate string, and nodes are "connected" 
to each other if they are not already visited and are one move away from each other...

board = {
{ 1,2,3 },
{ 4,0,5 },
};

begin = 123405

depth 0:           123405   <== 0 is at index 4, nextMoves[4]={1,3,5}, so swap 0 with the value
                 /   |    \       at each index 1,3,5 to form the next candidates to be pushed
                /    |     \      onto q in preparation for the next depth of processing
               /     |      \      
depth 1:    103425  123045  123450   <== next candidates pushed onto q
                           (target)
Since BFS is used, all candidates at each depth are checked before proceeding to the next depth. So for this example, depth=1 is returned, since the right-most candidate equals the target value 123450.

*/

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string str = to_string(board[0][0])+ to_string(board[0][1])+ to_string(board[0][2])+
            to_string(board[1][0])+ to_string(board[1][1])+ to_string(board[1][2]);
        unordered_map<int,vector<int>> nextMoves {{0,{1,3}},{1,{0,2,4}},{2,{1,5}},{3,{0,4}},{4,{1,3,5}},{5,{2,4}}};
        string target = "123450";
        int index = str.find("0");
        unordered_set<string> visited;
        queue<pair<int,pair<string,int>>> Q;
        Q.push({0,{str,index}});
        visited.insert(str);
        while(!Q.empty()) {
            int size = Q.size();
            for(int k=0; k<size; k++) {
                pair<int,pair<string,int>> ip = Q.front();
                int depth = ip.first;
                string candidate = ip.second.first;
                int index = ip.second.second;
                Q.pop();
                if(candidate == target) return depth;
                for(int next_index : nextMoves[index]) {
                    auto candidates = candidate;
                    swap(candidates[index],candidates[next_index]);
                    if(visited.find(candidates) == visited.end()) {
                        Q.push({depth+1,{candidates,next_index}});
                        visited.insert(candidates);
                    }
                }
            }
        }
        return -1;
    }
};