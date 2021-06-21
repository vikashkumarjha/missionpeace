/*
Given two version numbers, version1 and version2, compare them.

Version numbers consist of one or more revisions joined by a dot '.'. Each revision consists of digits and may contain leading zeros. Every revision contains at least one character. Revisions are 0-indexed from left to right, with the leftmost revision being revision 0, the next revision being revision 1, and so on. For example 2.5.33 and 0.1 are valid version numbers.

To compare version numbers, compare their revisions in left-to-right order. Revisions are compared using their integer value ignoring any leading zeros. This means that revisions 1 and 001 are considered equal. If a version number does not specify a revision at an index, then treat the revision as 0. For example, version 1.0 is less than version 1.1 because their revision 0s are the same, but their revision 1s are 0 and 1 respectively, and 0 < 1.

Return the following:

If version1 < version2, return -1.
If version1 > version2, return 1.
Otherwise, return 0.
 

Example 1:

Input: version1 = "1.01", version2 = "1.001"
Output: 0
Explanation: Ignoring leading zeroes, both "01" and "001" represent the same integer "1".
Example 2:

Input: version1 = "1.0", version2 = "1.0.0"
Output: 0
Explanation: version1 does not specify revision 2, which means it is treated as "0".

*/

#include "../header.hpp"


class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream ss1(version1);
        istringstream ss2(version2);
        
        string v1;
        string v2;
        while (!ss1.eof() || !ss2.eof()) {
            if (!ss1.eof()) {
                getline(ss1, v1, '.');
            }else {
                v1 = "0";
            }
            
            if (!ss2.eof()) {
                getline(ss2, v2, '.');
            }else {
                v2 = "0";
            }
            
            int n1 = stoi(v1);
            int n2 = stoi(v2);
            
            if ( n1 == n2) continue;
            if ( n1 > n2) return 1;
            if ( n1 < n2) return -1;
            
            
        }
        return 0;
        
    }
};