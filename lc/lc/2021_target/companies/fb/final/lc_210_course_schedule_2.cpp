/*
 * There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.



Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].


*/

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
