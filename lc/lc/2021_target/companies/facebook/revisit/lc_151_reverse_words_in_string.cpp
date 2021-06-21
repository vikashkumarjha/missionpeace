class Solution {
public:
    string reverseWords(string s) {
        int start;
        int n = s.size();
        for ( start = 0; start < n; start++ ) {
            if ( !isspace(s[start])) break;
        }
        
        int end;
        for ( end = n - 1; end >= 0; end--) {
            if (!isspace(s[end])) break;
        }
        
        int len = 0;
        for ( int i = start; i <= end; i++){
            if ( s[i] == ' ' && s[i-1] == ' '){
                continue;
            }
            s[len++] = s[i];
        }
        s.erase(s.begin()+len, s.end());
        reverse(s.begin(), s.end());
        
        int last = 0;
        
        for ( int i = 0; i < s.size(); i++)
        {
            if ( isspace(s[i])) {
                reverse(s.begin() + last, s.begin() + i );
                last = i + 1;
            }
            
        }
        
        reverse(s.begin() + last, s.end());
        return s;
        perm
    }
};


//reverse(s.begin() + last, s.begin()+i);