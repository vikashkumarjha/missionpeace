class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l = 0;
        int r = 0;
        int res = 0;
        map<int,int> hash;
        for ( ; r < n; r++){
            if ( hash.count(s[r]) ) {
                l = max(l, hash[s[r]]);
            }
            res = max(res, r - l + 1);
            hash[s[r]] = r + 1;
        }
        return res;
        
    }
};