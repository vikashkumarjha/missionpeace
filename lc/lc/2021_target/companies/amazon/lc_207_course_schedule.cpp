/*

There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.

             */


#include "header.hpp"            


class Solution {
       
private:
    vector<int> indegree;
    vector<unordered_set<int>> buildGraph(int numCourses, vector<vector<int>>& prerequisites){
        vector<unordered_set<int>> g(numCourses);
        indegree.resize(numCourses,0);
        for ( auto p : prerequisites){
            g[p[1]].insert(p[0]);
            indegree[p[0]]++;
        }
        return g;
    }
    
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
    vector<unordered_set<int>> g = buildGraph( numCourses,  prerequisites);
    queue<int> q;
    for ( int i = 0; i < indegree.size(); i++){
        if ( indegree[i] == 0 ){
            q.push(i);
        }
    }
    int cnt = 0;
   
        
    while ( !q.empty()){
        int curr = q.front();
        q.pop();
        for ( auto it = g[curr].begin(); it != g[curr].end(); it++){
            if (--indegree[*it] == 0){
                q.push(*it);
            }
         }
        cnt++;
    }
    return cnt == numCourses;
        
    }
};