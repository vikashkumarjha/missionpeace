bool wordBreak(string s, vector<string>& wordDict) {
    set<string> dict(wordDict.begin(), wordDict.end());
    int N = s.size();

    vector<int> DP(N+1, 0);

    DP[0] = true;

    for ( int i = 1; i <= N; i++) {
        for ( int j = 0; j < i; j++) {
            if ( DP[j]) {
                string w = s.substr(j, i - j);
                if ( dict.find(w) != dict.end()) {
                    DP[i] = true;
                    break;
                }
            }
        }
    }
    return DP[N];
}
