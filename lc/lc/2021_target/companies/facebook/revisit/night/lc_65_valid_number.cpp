class Solution {
public:
    bool isNumber(string s) {
        if ( s.empty()) return false;
        int i = 0;
        int n = s.size();
        
        while ( i < n && isspace(s[i])){
            i++;
        }
        
        if ( s[i] == '+' || s[i] == '-') {
            i++;
        }
        
        
        int dots = 0;
        int digits = 0;
        for (; i < n; i++) {
            if ( isdigit(s[i]) ) {
                digits++;
            }
            else if (s[i] == '.') {
                dots++;
            }
            else {
                break;
            }
        }
        
        if ( !digits || dots > 1) {
            return false;
        }
        
        if ( s[i] == 'e' || s[i] == 'E') {
            i++;
            if (s[i] == '+' || s[i] == '-') {
                i++;
            }
            digits = 0;
            dots = 0;
            for ( ; i < n; i++) {
                if ( isdigit(s[i])) {
                    digits++;
                }
                else {
                    break;
                }
                
            }
            if (!digits) return false;
            
        }
        
        while ( i < n && isspace(s[i])) {
            i++;
        }
        
        return i == n;
        
    }
};