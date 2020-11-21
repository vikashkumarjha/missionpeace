string minWindow(string s, string t) {
    int N1 = s.length();
    int N2 = t.length();
    int minWindowSize = INT_MAX;
    if ( N2 > N1) return "";
    
    int hash_pat[256] = {0};
    int hash_src[256] = {0};

    for (auto c : t ) {
        hash_pat[c]++;
    }

    int index = -1;
    int l = 0;
    int count = 0;
    for ( int r = 0; r < N1; r++) {
        hash_src[s[r]]++;
        if ( hash_pat[s[r]] != 0 && hash_pat[s[r]] >= hash_src[s[r]] ) {
            ++count;
        }
        if ( count == N2) {
            while ( hash_src[s[l]] == 0 || hash_src[s[l]] > hash_pat[s[l]]) {
                if ( hash_src[s[l]] > hash_pat[s[l]]) {
                    hash_src[s[l]]--;
                }
                l++;
            }
            int winLen = r - l + 1;
            if ( winLen < minWindowSize) {
                index = l;
                minWindowSize = winLen;
            }

        }
        return ( index == -1) ? "" : s.substr(index, minWindowSize);

    }
}
