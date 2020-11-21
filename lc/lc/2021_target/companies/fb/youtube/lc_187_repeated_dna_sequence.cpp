/*
 * All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

Example:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

Output: ["AAAAACCCCC", "CCCCCAAAAA"]

*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        std::vector<std::string> r;
        if ( s.length() < 10 )
            return r;
        std::unordered_map<std::string,int > f;

        for ( int i = 0; i <= s.length() - 10 ; ++i)
        {
            std::string curr = s.substr(i,10);
            f[curr]++;

        }
        for ( auto it = f.begin() ; it != f.end(); ++it)
        {
            if ( it->second > 1)
                r.push_back(it->first);
        }
        return r;
    }
};
