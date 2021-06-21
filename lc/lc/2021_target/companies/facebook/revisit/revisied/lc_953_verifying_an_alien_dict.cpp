/*
 * In an alien language, surprisingly they also use english lowercase letters,
 * but possibly in a different order. The order of the alphabet is some
 * permutation of lowercase letters.
 *
 * Given a sequence of words written in the alien language, and the order of the
 * alphabet, return true if and only if the given words are sorted
 * lexicographicaly in this alien language.
 *
 *  
 *
 *  Example 1:
 *
 *  Input: words = ["hello","leetcode"], order = "hlabcdefgi
 *  pqrstuvwxyz"
 *  Output: true
 *  Explanation: As 'h' comes before 'l' in this language, then the sequence is
 *  sorted.
 *  Example 2:
 *
 *  Input: words = ["word","world","row"], order = "worldabcefghiIn an alien lanuage, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.
 * utput: false
 * Explanation: As 'd' comes after 'l' in this language, then words[0] >
 * words[1], hence the sequence is unsorted.
 *

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.

 

Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.

*/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,char> m;
        for ( int i = 0; i < order.size(); i++)
        {
            m[order[i]] = 'a' + i;
        }
        // now transform the words

        for ( auto &w : words) {
            for ( auto &c : w) {
                c = m[c];
            }
        }

        return is_sorted(begin(words), end(words));
    }
};



class Solution2 {
public:
    bool isAlienSorted(vector<string>& words, string order) {

        unordered_map<char,int> m;
        for ( int i = 0; i < order.size(); i++) {
            m[order[i]] = i;
        }

        vector<string> toSort(begin(words), end(words));
        sort(begin(toSort), end(toSort),[&](string a, string b) {
                int n = min(a.size(), b.size());
                for ( int i = 0; i < n; i++) {
                if ( a[i] != b[i]) {
                return m[a[i]] < m[b[i]];
                }

                }
                return a.size() < b.size();

                });

        return ( toSort == words);
    }
};
