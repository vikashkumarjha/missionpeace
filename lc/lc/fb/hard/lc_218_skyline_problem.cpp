class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> edges;
        int left, right, height;
        for(int i=0; i<buildings.size(); i++){
            left=buildings[i][0];
            right=buildings[i][1];
            height=buildings[i][2];
            /*** make sure : for the same left point we use the bigger height ***/
            edges.push_back(make_pair(left, -height));
            edges.push_back(make_pair(right, height));
        }
        sort(edges.begin(), edges.end());
        vector<pair<int, int>> result;
        /*** use the multiset to store the max height util current pos ***/
        multiset<int> m;
        /*** left most height ***/
        m.insert(0);
        int pre=0, cur=0;
        for(int i=0; i<edges.size(); i++){
            pair<int, int> e=edges[i];
            if(e.second < 0)  m.insert(-e.second);
            else m.erase(m.find(e.second));
            cur=*(m.rbegin());
            if(cur!=pre){
                result.push_back(make_pair(e.first, cur));
                pre=cur;
            }
        }
        return result;
    }
};


class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int> > h;
        vector<vector<int>> res;
        multiset<int> m;
        int pre = 0, cur = 0;
        for (auto &a : buildings) {
            h.push_back({a[0], -a[2]});
            h.push_back({a[1], a[2]});
        }
        sort(h.begin(), h.end());
        m.insert(0);
        for (auto &a : h) {
            if (a.second < 0) m.insert(-a.second);
            else m.erase(m.find(a.second));
            cur = *m.rbegin();
            if (cur != pre) {
                res.push_back({a.first, cur});
                pre = cur;
            }
        }
        return res;
    }
};
