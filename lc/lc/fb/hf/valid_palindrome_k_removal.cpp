
bool isValid(const string &s, int l, int r, int k) {
    if ( l >= r) return true;
    if ( s[l] == s[r]) 
        return isValid(s, l + 1, r -1, k);

    return ( k > 0 && (isValid(s, l+1, r, k -1 ) || isValid(s, l, r - 1, k - 1)));

}



bool validPalindrome(string s) { 
    if ( s.empty()) return true;
    return isValid(s, 0, s.length() - 1, 1);



}
