class Solution {
public:

    void bfs(std::vector<unordered_set<int>> &g, int node , std::vector<bool> &isVisited){
        queue<int> q;
        q.push(node);
        while ( !q.empty()){
            auto n = q.front();
            q.pop();
            for ( auto it = g[n].begin(); it != g[n].end(); it++){
                if ( !isVisited[*it] ){
                    isVisited[*it] = true;
                    q.push(*it);
                }
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {

        std::vector<unordered_set<int>> g(n,  unordered_set<int>());
        for ( auto e : edges){
            g[e[0]].insert(e[1]);
            g[e[1]].insert(e[0]);
        }

        std::vector<bool> isVisited(n, false);
        int noOfComponents = 0;
        for ( int i = 0; i < n; i++ ){
            if (isVisited[i] == false){
                bfs(g, i, isVisited);    
                ++noOfComponents;
            }    
        }
        return noOfComponents;

    }
};


class Solution {
private :
    int find(vector<int> & parent, int x){
        if (parent[x] == x)
            return x;

        return find(parent, parent[x]);
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int subGraphCount = n;
        vector<int> parent(n);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (const auto & e : edges){
            int  x = e[0];
            int  y = e[1];

            int px = find(parent, x);
            int py = find(parent, y);

            if (px != py){
                subGraphCount--;
                parent[py] = px;
            }
        }

        return subGraphCount;
    }
};


class Solution {
public:
    vector<vector<int>> edgeMap;
    vector<bool> visit;

    void dfs(int id)
    {
        visit[id] = true;
        for(int nei : edgeMap[id])
        {
            if(visit[nei] == false) dfs(nei);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        edgeMap.resize(n);
        visit.resize(n, false);
        for(vector<int> v : edges)
        {
            edgeMap[v[0]].push_back(v[1]);
            edgeMap[v[1]].push_back(v[0]);
        }
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(visit[i] == false)
            {
                dfs(i);
                cnt++;
            }
        }
        return cnt;
    }
};
