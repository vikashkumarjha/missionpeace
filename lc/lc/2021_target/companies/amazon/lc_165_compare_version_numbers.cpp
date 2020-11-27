/*
Given two version numbers, version1 and version2, compare them.

Version numbers consist of one or more revisions joined by a dot '.'. Each revision consists of digits and may contain leading zeros. Every revision contains at least one character. Revisions are 0-indexed from left to right, with the leftmost revision being revision 0, the next revision being revision 1, and so on. For example 2.5.33 and 0.1 are valid version numbers.

To compare version numbers, compare their revisions in left-to-right order. Revisions are compared using their integer value ignoring any leading zeros. This means that revisions 1 and 001 are considered equal. If a version number does not specify a revision at an index, then treat the revision as 0. For example, version 1.0 is less than version 1.1 because their revision 0s are the same, but their revision 1s are 0 and 1 respectively, and 0 < 1.

Return the following:

If version1 < version2, return -1.
If version1 > version2, return 1.
Otherwise, return 0.

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <sstream>

using namespace std;






class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream v1(version1);
        istringstream v2(version2);
        string num1;
        string num2;
        while (!v1.eof() || !v2.eof()) {
            if ( !v1.eof()) {
                getline(v1, num1,'.');    
            }else {
                num1 = "0";
            }
            if ( !v2.eof()) {
                getline(v2, num2,'.');    
            }else {
                num2 = "0";
            }
            
            int n1 = stoi(num1);
            int n2 = stoi(num2);
            
            if ( n1 > n2) {
                return 1;
            }
            else if ( n1 < n2){
                return -1;
            } 
            else 
                continue;
            
            
        }
        return 0;
        
        
        
        
        
    }
};