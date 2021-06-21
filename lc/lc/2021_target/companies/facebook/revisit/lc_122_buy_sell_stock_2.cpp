You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int res = 0;
        for ( int i = 1; i < p.size(); i++) {
            if ( p[i] > p[i-1]) {
                res += p[i] - p[i-1];
            }
            
        }
        return res;
    }
};