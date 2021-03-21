/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        
        for ( auto s : strs) {
            auto k = s;
            sort(k.begin(), k.end());
            m[k].push_back(s);
            
        }
        
        for ( auto it : m) {
            res.push_back(it.second);
        }
        
        
        return res;
        
        
    }
};