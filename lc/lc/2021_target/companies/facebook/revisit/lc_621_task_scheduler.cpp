/*
Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

Return the least number of units of times that the CPU will take to finish all the given tasks.

 

Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: 
A -> B -> idle -> A -> B -> idle -> A -> B
There is at least 2 units of time between any two same tasks.
Example 2:

Input: tasks = ["A","A","A","B","B","B"], n = 0
Output: 6
Explanation: On this case any permutation of size 6 would work since n = 0.
["A","A","A","B","B","B"]
["A","B","A","B","A","B"]
["B","B","B","A","A","A"]
...
And so on.

*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char,int> m;
        
        for ( auto t : tasks) {
            m[t]++;
        } 
        
        priority_queue<int,vector<int>> pq;
        for ( auto e : m) {
            pq.push(e.second);
        }
        int res = 0;
        
        while ( !pq.empty()) {
            
            int cycle = n + 1;
            vector<int> tmp;
            int curr = 0;
            while ( cycle-- && !pq.empty()) {
                auto x = pq.top(); pq.pop();
                curr++; x--;
                if ( x > 0) {
                    tmp.push_back(x);
                } 
                
            }
            if ( tmp.size() == 0) {
                res += curr;
            }else {
                res += (n+1);
                for ( int k = 0; k < tmp.size(); k++) {
                    pq.push(tmp[k]);
                }
            }
            
        }
        
        return res;
        
    }
};