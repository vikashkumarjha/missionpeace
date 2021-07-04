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
