/*
Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.

Example 1:

Input: S = "loveleetcode", C = 'e'
Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]


*/

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        std::set<int> indexSet;
        std::vector<int> r( S.length(), 0 );
        for ( int i = 0; i < S.length(); i++)
        {
                if ( S[i] == C) {
                        indexSet.insert(i);
                }
        }
        for ( int i = 0; i < S.length(); i++)
        {
                if ( S[i] != C) {
                        int diff = INT_MAX;
                        for ( auto index : indexSet) {
                                diff = std::min( diff, std::abs(index - i));
                        }
                        r[i] = diff;
                }
        }
        return r;
}
};