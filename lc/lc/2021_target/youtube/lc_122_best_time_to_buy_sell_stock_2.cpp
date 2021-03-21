/*
Say you have an array prices for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.

 */


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int n = prices.size();
        int valley = prices[0];
        int res = 0;
        int peak = prices[0];
        while ( i < n - 1) {
            // find the valley
            while ( i < n-1 && prices[i] >= prices[i+1]) i++;
            valley = prices[i];
            //find the peak
            while (  i < n -1 && prices[i] <= prices[i+1]) i++;
            peak = prices[i];
            res += peak - valley;
            
        }
        
        return res;
        
    }
};


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

