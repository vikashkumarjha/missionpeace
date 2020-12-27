/*
There are a total of n courses you have to take labelled from 0 to n - 1.

Some courses may have prerequisites, for example, if prerequisites[i] = [ai, bi] this means you must take the course bi before the course ai.

Given the total number of courses numCourses and a list of the prerequisite pairs, return the ordering of courses you should take to finish all courses.

If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

*/


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        
        vector<int> indegree(numCourses,0);
        vector<unordered_set<int>> g(numCourses, unordered_set<int>());
        for ( auto p : pre) {
            indegree[p[0]]++;
            g[p[1]].insert(p[0]);
            
        }
        vector<int> res;
        queue<int> q;
        
        for ( int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while ( !q.empty()) {
            auto n = q.front(); q.pop();
            res.push_back(n);
            for ( const auto &neigh : g[n]){
                indegree[neigh]--;
                if ( indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
            
        }
        
        if ( res.size() != numCourses) {
            return {};
        }
        return res;
        
        
        
        
    }
};