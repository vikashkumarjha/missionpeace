
void helper(int pair, int index, int removeLeft, int removeRight, const string &s,  string current, unordered_set<string> &res) {
    if ( index == s.size()) {
        if ( pair == 0 && !removeLeft && !removeRight) {
            res.insert(current);
        }

        return;
    }

    if ( s[index] == '(') {
        //exclude 
        if ( removeLeft)
            helper(pair, index + 1, removeLeft - 1, removeRight, s, curr, result);
        helper(pair + 1, index + 1, removeLeft , removeRight, s, curr + s[index], result);
    }
    else if ( s[index] == ')') {
        //exclude 
        if ( removeRight)
            helper(pair, index + 1, removeLeft, removeRight - 1, s, curr, result);
        if ( pair > 0 )
            helper(pair - 1, index + 1, removeLeft , removeRight, s, curr + s[index], result);
    }else {
        helper(pair, index + 1, removeLeft, removeRight, s, curr + s[index], result);
    }
}

vector<string> removeInvalidParentheses(string s) {
    int removeLeft = 0;
    int removeRight = 0;

    unordered_set<string> result;

    for ( auto c : s) {
        if ( c == '(') {
            removeLeft++;
        }else if ( c == ')') {
            if ( removeLeft > 0 ) --removeLeft;
            else {
                removeRight++;
            }
        }
    }

    helper(0, 0, removeLeft, removeRight, "", result);
    return vector<string>(res.begin(), res.end());
}

