class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> sFreq(256,0);
        vector<int> pFreq(256,0);
        vector<int> res;
        
        if ( s.size() < p.size()) return res;
        
        for ( int i = 0; i < p.size(); i++) {
            sFreq[s[i]]++;
            pFreq[p[i]]++;
        }
        
        
        if ( sFreq == pFreq) {
            res.push_back(0);
        } 
        
        for ( int r = p.size(); r < s.size(); r++) {
          
            sFreq[s[r]]++;
            sFreq[s[r - p.size()]]--;
            if ( sFreq == pFreq){ 
                res.push_back(r - p.size() + 1);
            }
            
        }
        
        return res;
       
    }
};