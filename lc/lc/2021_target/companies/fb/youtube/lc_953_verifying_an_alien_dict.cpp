
/*
 * In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.



Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.

*/


class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,char> hash;
        int N = order.size();

        for ( int i = 0; i < N; i++) {
            hash[order[i]] = 'a' + i;
        }


        // lets map the
        for ( auto &w : words) {
            for ( auto &c : w) {
                c = hash[c];
            }

        }
        return is_sorted(words.begin(), words.end());
    }
};
