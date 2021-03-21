/*

Given a string s containing only digits, return all possible valid IP addresses that can be obtained from s. You can return them in any order.

A valid IP address consists of exactly four integers, each integer is between 0 and 255, separated by single dots and cannot have leading zeros. For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses and "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses. 

 

Example 1:

Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]
Example 2:

Input: s = "0000"
Output: ["0.0.0.0"]

*/
class Solution {
public:
    
    void helper(string s, int idx, string ip, vector<string> &res) {
        if ( idx > 3) {
            if (s.empty()) {
                res.push_back(ip);
                
            }
            return;
        }
        
        for ( int k = 1; k < 4; k++) {
            if ( s.size() < k ) break;
            
            string s1 = s.substr(0, k);
            string s2 = s.substr(k);
            
            if ( stoi(s1) > 255 || (s1[0] == '0' && s1.length() > 1)) 
                break;
            
            helper(s2, idx+1, ip + s1 + (idx == 3 ? "" : "."), res);
            
        }
        
    }
   
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string ip;
        helper(s, 0, ip,res);
        return res;
       
    }
};