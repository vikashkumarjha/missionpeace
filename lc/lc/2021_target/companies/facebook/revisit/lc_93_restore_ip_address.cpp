class Solution {
public:
    
    void helper(string s, int count, string ip, vector<string> &res)
    {
        if ( count > 3){
            if ( s.empty()) {
                res.push_back(ip);
            }    
            return;
        }
        
        for ( int i = 1; i < 4; i++)
        {
            if ( s.size() < i) break;
            string s1 = s.substr(0, i);
            string s2 = s.substr(i);
            
           
            if ( stoi(s1) > 255 ||( s1[0] == '0' && s1.size() > 1)) break;
           
            string x = ip + s1 + (count == 3 ? "" : "."); 
            helper(s2, count + 1, x, res );
            
        }
        
    }
    
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if ( s.empty()) return res;
        
        helper(s, 0, "",  res);
        return res;
        
    }
};