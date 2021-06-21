/*
Given a string s and an integer k, rearrange s such that the same characters are at least distance k from each other. If it is not possible to rearrange the string, return an empty string "".

 

Example 1:

Input: s = "aabbcc", k = 3
Output: "abcabc"
Explanation: The same letters are at least a distance of 3 from each other.
Example 2:

Input: s = "aaabc", k = 3
Output: ""
Explanation: It is not possible to rearrange the string.
*/

class Solution {
public:
    string rearrangeString(string str, int k) {
        if(k == 0) return str;
        int length = (int)str.size(); 
        
        string res;
        unordered_map<char, int> dict;
        priority_queue<pair<int, char>> pq;
        
        for(char ch : str) dict[ch]++;
        for(auto it = dict.begin(); it != dict.end(); it++){
            pq.push(make_pair(it->second, it->first));
        }
        
        while(!pq.empty()){
            vector<pair<int, char>> cache; //store used char during one while loop
            int count = min(k, length); //count: how many steps in a while loop
            for(int i = 0; i < count; i++){
                if(pq.empty()) return "";
                auto tmp = pq.top();
                pq.pop();
                res.push_back(tmp.second);
                if(--tmp.first > 0) cache.push_back(tmp);
                length--;
            }
            for(auto p : cache) pq.push(p);
        }
        return res;
    }
};