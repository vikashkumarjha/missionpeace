/*
 * A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.

*/

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int>res;
        vector<int>pos(26);
        for(int i = 0; i < S.size(); i++) pos[S[i] - 'a'] = i;
        int maxPos = 0, pre = -1;
        for(int i = 0; i < S.size(); i++){
            maxPos = max(maxPos, pos[S[i] - 'a']);
            if(i == maxPos){
                res.push_back(i - pre);
                pre = i;
            }
        }
        return res;
    }
};
