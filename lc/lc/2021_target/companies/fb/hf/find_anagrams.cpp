vector<int> findAnagrams(string s, string p) {
    vector<int> mp(256);
    vector<int> ms(256);
    vector<int> result;

    for ( int i = 0; i < p.size(); i++) {
        mp[p[i]]++;
        ms[s[i]]++;
    }
    if ( mp == ms) {
        result.push_back(0);
    }

    for ( int i = p.size(); i < s.size(); i++) {
        ++ms[s[i]]++;
        --ms[s[i - p.size()]];
        if ( ms == mp) {
            result.push_back(i - p.size() + 1);
        }
    }
    return result;

}
