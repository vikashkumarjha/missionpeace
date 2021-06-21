class Solution {
public:
    
    int distance(vector<int>& p1, vector<int>& p2) {
        return pow((p1[0] - p2[0]), 2) + pow((p1[1] - p2[1]), 2);
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> sides = { p1, p2, p3, p4};
        
        map<int,int> m;
        
        for ( int i = 0; i < sides.size(); i++) {
            for ( int j = i + 1; j < sides.size(); j++) {
                int dist = distance(sides[i], sides[j]);
                m[dist]++;        
            }
        }
        if ( m.size() != 2) return false;
        auto it = m.begin();
        int sideCount = it->second;
        it++;
        int diagCount = it->second;
        return sideCount == 4 and diagCount == 2;
        
    }
};