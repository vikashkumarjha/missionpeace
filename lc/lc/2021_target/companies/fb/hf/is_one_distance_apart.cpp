class Solution {
public:
    bool isOneEditDistance(string s, string t) {
          if (s==t)
            return false;
        int M=(int)s.size(),N=(int)t.size();
        if (abs(M-N) > 1)
            return false;
        int i=0,j=0,diff=0;
        while (i<M && j<N){
            if (s[i]==t[j]){
                ++i,++j;
                continue;
            }
            if (++diff > 1)
                return false;
            if(M==N){
                ++i,++j;
                continue;
            }else{
                if (M>N)
                    ++i;
                else
                    ++j;
            }
        }
        return true;
    
        
    }
};