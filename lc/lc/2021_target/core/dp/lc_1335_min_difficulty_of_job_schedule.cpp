/*
You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work on the i-th job, you have to finish all the jobs j where 0 <= j < i).

You have to finish at least one task every day. The difficulty of a job schedule is the sum of difficulties of each day of the d days. The difficulty of a day is the maximum difficulty of a job done in that day.

Given an array of integers jobDifficulty and an integer d. The difficulty of the i-th job is jobDifficulty[i].

Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs return -1.

*/

#define INF 300001;
class Solution {
public:
    int dp[305][15];
    int n;
    int f(vector<int> &jd, int d, int idx) {
        if(d == 0 && idx == n)
            return 0;
        if(d == 0 || idx == n || n - idx < d)
            return INF;
        if(dp[idx][d] != -1)
            return dp[idx][d];
        int ans = INF;
        int mx = -INF;
        for(int i = idx; i < n; i++) {
            mx = max(mx, jd[i]);
            ans = min(ans, mx + f(jd, d - 1, i + 1));
        }
        return dp[idx][d] = ans;
    }
    int minDifficulty(vector<int>& jd, int d) {
        n = jd.size();
        if(n < d)
            return -1;
        memset(dp,-1,sizeof(dp));
        return f(jd, d, 0);
    }
};


 int minDifficulty(vector<int>& A, int D) {
        int n = A.size(), inf = 1e9, maxd;
        if (n < D) return -1;
        vector<int> dp(n + 1, 1e9);
        dp[n] = 0;
        for (int d = 1; d <= D; ++d) {
            for (int i = 0; i <= n - d; ++i) {
                maxd = 0, dp[i] = inf;
                for (int j = i; j <= n - d; ++j) {
                    maxd = max(maxd, A[j]);
                    dp[i] = min(dp[i], maxd + dp[j + 1]);
                }
            }
        }
        return dp[0];
    }