class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        
        vector<int> pos(n1+n2,0);
        
        for ( int i = n1-1; i >= 0; i--) {
            for ( int j = n2-1; j >= 0; j--) {
                int p1 = i + j;
                int p2 = i + j + 1;
                
                int val = (num1[i] - '0') * (num2[j] - '0');
                int sum = val + pos[p2];
                
                pos[p2] = sum % 10;
                pos[p1] = pos[p1] + ( sum / 10);
                
                
            }
            
        }
        
        string res;
        for ( int d : pos) {
            if (!((res.size() == 0 && d == 0))) {
                res += to_string(d);
            }
        }
        if ( res.empty()) 
            return "0";
        return res;
        
        
    }
};