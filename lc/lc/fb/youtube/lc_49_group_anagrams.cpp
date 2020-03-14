/*
 * Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
*/


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         std::unordered_map<std::string,std::vector<std::string> > m;
    int i = 0;
    for ( auto s : strs)
    {
        std::sort(s.begin(),s.end());
        m[s].push_back(strs[i++]);

    }
    std::vector<std::vector<std::string> > res;

    for ( auto e : m){
        res.push_back(e.second);
    }

    return res;

    }
};
