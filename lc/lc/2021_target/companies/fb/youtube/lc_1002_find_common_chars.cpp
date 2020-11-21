/*
Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates).  For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.

You may return the answer in any order.

 

Example 1:

Input: ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: ["cool","lock","cook"]
Output: ["c","o"]
*/

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
          std::vector<string> res;
        //lets sort the vector and pick the mininum length string
        std::sort(A.begin(), A.end(), [](std::string& a , std::string& b){
                return a.length() < b.length();
        });

        std::map<char,int> m;
        for ( auto c : A[0]) {
                m[c]++;
        }
        for ( int i = 1; i < A.size(); i++)
        {
                std::map<char,int> tmp;
                for ( auto c : A[i])
                        tmp[c]++;

                for ( auto it = m.begin(); it != m.end(); it++)
                {
                        if ( !tmp.count(it->first))
                        {
                                it->second = 0;
                                continue;
                        }
                        it->second = std::min(it->second,tmp[it->first]);
                }
        }
        //build the result
        for ( auto it = m.begin(); it != m.end(); it++)
        {
                for ( int i = 0; i < it->second; i++)
                        res.push_back(std::string(1,it->first));

        }
        return res;
        
    }
};