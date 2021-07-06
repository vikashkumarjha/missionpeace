class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     std::unordered_map<int,int> m;
        for ( auto n : nums ) {
                m[n]++;
        }
        std::priority_queue<std::pair<int,int>> pq;

        for ( auto it = m.begin(); it != m.end(); it++)
        {
                pq.push(std::make_pair(it->second,it->first));
        }
        int count = 0;
        std::vector<int> result;

        while ( !pq.empty()){
                auto it = pq.top();
                ++count;
                pq.pop();
                result.push_back(it.second);
                if ( count == k ) break;
        }
        return result;
    }
};
