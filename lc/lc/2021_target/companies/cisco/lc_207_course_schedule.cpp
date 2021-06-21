/*
 * There are a total of numCourses courses you have to take, labeled from 0 to
 * numCourses - 1. You are given an array prerequisites where prerequisites[i] =
 * [ai, bi] indicates that you must take course bi first if you want to take
 * course ai.
 *
 * For example, the pair [0, 1], indicates that to take course 0 you have to
 * first take course 1.
 * Return true if you can finish all courses. Otherwise, return false.
 *
 *
 *
 *  Example 1:
 *
 *  Input: numCourses = 2, prerequisites = [[1,0]]
 *  Output: true
 *  Explanation: There are a total of 2 courses to take.
 *  To take course 1 you should have finished course 0. So it is possible.
 *  Example 2:
 *
 *  Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
 *  Output: false
 *  Explanation: There are a total of 2 courses to take.
 *  To take course 1 you should have finished course 0, and to take course 0 you
 *  should also have finished course 1. So it is impossible.
 *
 *  */

#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <queue>
#include <list>


using namespace std;







class Solution {

private:
    vector<int> indegree;
    vector<unordered_set<int>> buildGraph(int n, vector<vector<int>> pre) {
            vector<unordered_set<int>> g(n);
            indegree.resize(n,0);

            for ( auto p : pre) {
                indegree[p[0]]++;
                g[p[1]].insert(p[0]);
            }
            return g;
    }


public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<unordered_set<int>> g = buildGraph(numCourses, pre);
        queue<int> q;
        for ( int i = 0; i < indegree.size(); i++)
        {
                if ( indegree[i] == 0) {
                        q.push(i);
                }
        }
        int cnt = 0;
        while (!q.empty()) {
            auto curr = q.front(); q.pop();
            for ( auto it = g[curr].begin(); it != g[curr].end(); it++)
            {
                    if (--indegree[*it] == 0)
                    {
                        q.push(*it);
                    }
            }
            cnt++;
        }
        return cnt == numCourses;
    }
};
