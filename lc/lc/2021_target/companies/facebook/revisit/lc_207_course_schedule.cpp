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