class Solution {
public:
    string intToRoman(int num) {
        stringstream ss;
        vector<pair<string,int>> m= {
            {"M", 1000}, 
            {"CM", 900},
            {"D", 500},
            {"CD", 400},
            {"C", 100},
            {"XC", 90},
            {"L", 50},
            {"XL", 40},
             {"X", 10},
             {"IX", 9},
             {"V", 5},
            {"IV", 4},
            {"I", 1},
            
        };
        for ( int i = 0; i < m.size() && num > 0; i++) {
            while ( num >= m[i].second) {
                ss << m[i].first;
                num -= m[i].second;
            }
            
        }
        return ss.str();
        
    }
};