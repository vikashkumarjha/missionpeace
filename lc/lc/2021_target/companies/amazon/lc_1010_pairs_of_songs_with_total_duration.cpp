/*
In a list of songs, the i-th song has a duration of time[i] seconds. 

Return the number of pairs of songs for which their total duration in seconds is divisible by 60.  Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.

 

Example 1:

Input: [30,20,150,100,40]
Output: 3
Explanation: Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60


*/


class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> bucket(60,0);
        int res = 0;
        for ( int i = 0; i < time.size(); i++) {
            int bucketIndex = time[i] % 60;
            res += bucket[(60 - bucketIndex)%60];
            bucket[bucketIndex]++;
        }
        return res;
        
    }
};