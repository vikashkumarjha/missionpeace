/*
There are a total of n courses you have to take labelled from 0 to n - 1.

Some courses may have prerequisites, for example, if prerequisites[i] = [ai, bi] this means you must take the course bi before the course ai.

Given the total number of courses numCourses and a list of the prerequisite pairs, return the ordering of courses you should take to finish all courses.

If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].


*/


#include "header.hpp"

class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>> & pre) {
        vector<int> result;
        vector<int> inDegree(N, 0);
        vector<vector<int>> G(N, vector<int>());
        queue<int> q;
        
        for (const auto & p: pre){
            inDegree[p[0]]++; 
            G[p[1]].push_back(p[0]);
        }
        
        std::for_each(inDegree.begin(), inDegree.end(),[](int x){
            std::cout << " " << x;
        });
        
        
        for (int i = 0; i < N; i++){
            if (inDegree[i] == 0){
                q.push(i);
            }
        }
        
        while(q.empty() == false){
            int node = q.front(); 
            q.pop();
            result.push_back(node);
            
            for (const auto & x : G[node]) {
                 inDegree[x]--;
                 if (inDegree[x] == 0)
                     q.push(x);
            }
        }
        std::for_each(result.begin(), result.end(),[](int x){
            std::cout << " " << x;
        });
        
        if (result.size() == N)
            return result;
        
        return {};
    }
};