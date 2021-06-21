/*
 * You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.

Return true if you can make this square and false otherwise.

*/

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        sum = accumulate(matchsticks.begin(), matchsticks.end(), sum);
        if (matchsticks.size() < 4 || sum % 4) return false;

        vector<int>visited(matchsticks.size(), false);
        return backtrack(matchsticks, visited, sum / 4, 0, 0, 4);
    }

    bool backtrack(vector<int>& matchsticks,vector<int>visited, int target, int curr_sum, int i, int k) {
        if (k == 1) // if k == 1 then we found all subsets
            return true;

        if (curr_sum == target) // we found one subset, go on to the next one starting from curr_sum = 0
            return backtrack(matchsticks, visited, target, 0, 0, k-1);

        for (int j = i; j < matchsticks.size(); j++) {
            if (visited[j] || curr_sum + matchsticks[j] > target) continue; // if we visited this index already or curr_sum + matchsticks[j] > target then we can't use it

            visited[j] = true;
            if (backtrack(matchsticks, visited, target, curr_sum + matchsticks[j], j+1, k)) return true;
            visited[j] = false;
        }

        return false;
    }
};