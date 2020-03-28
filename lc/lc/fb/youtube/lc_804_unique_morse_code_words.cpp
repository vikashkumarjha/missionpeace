class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        std::set<std::string> s;
        std::stringstream ss;
        std::vector<std::string> morse_codes = {
                ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
        };

        for ( auto w : words ) {
                ss.str("");
                for (auto c : w ) {
                        ss << morse_codes[ c - 'a'];
                }
                s.insert(ss.str());
        }

        return s.size();
        
    }
};