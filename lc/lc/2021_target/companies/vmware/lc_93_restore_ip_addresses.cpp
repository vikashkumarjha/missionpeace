/*
Given a string s containing only digits, return all possible valid IP addresses that can be obtained from s. You can return them in any order.

A valid IP address consists of exactly four integers, each integer is between 0 and 255, separated by single dots and cannot have leading zeros. For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses and "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses. 

 

Example 1:

Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]

*/


#include <iostream>
#include <string>
#inclue <vector>

using namespace std;

class Solution {
public:
    
    void helper(string s, int count, string ip, vector<string> &res)
    {
        if ( count > 3){
            if ( s.empty()) {
                res.push_back(ip);
            }    
            return;
        }
        
        for ( int i = 1; i < 4; i++)
        {
            if ( s.size() < i) break;
            string s1 = s.substr(0, i);
            string s2 = s.substr(i);
            
           
            if ( stoi(s1) > 255 ||( s1[0] == '0' && s1.size() > 1)) break;
           
            string x = ip + s1 + (count == 3 ? "" : "."); 
            helper(s2, count + 1, x, res );
            
        }
        
    }
    
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if ( s.empty()) return res;
        
        helper(s, 0, "",  res);
        return res;
        
    }
};