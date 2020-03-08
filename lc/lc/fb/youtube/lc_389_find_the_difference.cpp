/*
 * Given two strings s and t which consist of only lowercase letters.
 *
 * String t is generated by random shuffling string s and then add one more
 * letter at a random position.
 *
 * Find the letter that was added in t.
 *
 * Example:
 *
 * Input:
 * s = "abcd"
 * t = "abcde"
 *
 * Output:
 * e
 *
 * Explanation:
 * 'e' is the letter that was added.
 *
 * */



class Solution {
public:
    char findTheDifference(string s, string t) {
        std::unordered_map<char,int> f;
        for ( int i = 0; i < t.length(); ++i){
            f[t[i]]++;
        }
        for ( int i = 0; i < s.length(); ++i){
            f[s[i]]--;
        }
        for ( auto it = f.begin(); it != f.end(); ++it){
            if ( it->second == 1 )
                return it->first;
        }
        return '#';

    }
};
