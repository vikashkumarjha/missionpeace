bool isAlienSorted(vector<string>& words, string order) {
    unordered_map<char,char> m;
    for ( int i = 0; i < order.size(); i++) {
        m[order[i]] = 'a' + i;
    }
    for ( auto &w : words) {
        for (auto &c : w) {
            c = m[c];
        }
    }

    return is_sorted(words.begin(), words.end());

}
