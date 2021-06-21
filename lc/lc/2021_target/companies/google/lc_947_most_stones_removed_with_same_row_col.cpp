/*
On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

 

Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
*/

class Solution {
    vector<int>parent;
    int find(int x) {
        return parent[x] == x ? x : find(parent[x]);
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        
        if (stones.empty()) return 0;
        
        int m = stones.size();
        
        parent.resize(m, 0);
        for (int i = 0; i < m; i++)
            parent[i] = i;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    int x = find(i);
                    int y = find(j);
                    if (x != y)
                        parent[y] = x;
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i < m; i++) {
            if (parent[i] == i)
                ans++;
        }
        
        return m-ans;
    }
};


class Solution {
public:
    int numOfConnectedStones(vector<vector<int>>& stones, unordered_map<int,vector<int>>& row, unordered_map<int,vector<int>>& col, vector<bool>& isStoneVisited, int n, int idx){
        int ans=0;
        isStoneVisited[idx]=true;
        ans++;
        int r=stones[idx][0],c=stones[idx][1];
        for(int i=0;i<row[r].size();i++){
            if(!isStoneVisited[row[r][i]]){
                ans+=numOfConnectedStones(stones,row,col,isStoneVisited,n,row[r][i]);
            }
        }
        for(int i=0;i<col[c].size();i++){
            if(!isStoneVisited[col[c][i]]){
                ans+=numOfConnectedStones(stones,row,col,isStoneVisited,n,col[c][i]);
            }
        }
        return ans;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<bool> isStoneVisited(n,0);
        unordered_map<int,vector<int>> row;
        unordered_map<int,vector<int>> col;
        for(int i=0;i<n;i++){
            row[stones[i][0]].push_back(i);
            col[stones[i][1]].push_back(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(!isStoneVisited[i]){
                int num=numOfConnectedStones(stones,row,col,isStoneVisited,n,i);
                ans+=(num-1);
            }
        }
        return ans;
    }
};