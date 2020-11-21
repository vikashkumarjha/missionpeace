int romanToInt(string s) {
    unordered_map<char,int> m = { {'I', 1},.....};
    int n = s.length();
    int result = 0;
    for ( int i = 0; i < n; i++) {
        int x = m[s[i]];
        if ( i + 1 < n ) {
            int y = m[s[i + 1]];
            if ( x >= y) {
                result += x;
            }else {
                result += ( y - x);
                i++;
            }
        }else {
            result += x;
        }
    }
    return result;

}
