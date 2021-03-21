/*
 *
 * Given two words word1 and word2, find the minimum number of operations
 * required to convert word1 to word2.
 *
 * You have the following 3 operations permitted on a word:
 *
 * Insert a character
 * Delete a character
 * Replace a character
 * Example 1:
 *
 * Input: word1 = "horse", word2 = "ros"
 * Output: 3
 * Explanation:
 * horse -> rorse (replace 'h' with 'r')
 * rorse -> rose (remove 'r')
 * rose -> ros (remove 'e')
 *
 * */

#include "header.hpp"
using namespace std;

int helper(string &w1, string &w2, int m, int n) {
    if ( m == 0  ) return n;
    if ( n == 0 ) return m;

    if ( w1[m-1] == w2[n-1]) {
        return helper(w1, w2, m-1, n-1);
    }

    return 1 + min( helper(w1, w2 , m, n -1) , min( helper(w1, w2,m - 1,n -1) , helper(w1, w2, m-1, n)));
}



int minDistance(string word1, string word2) {

    int m = word1.size();
    int n = word2.size();

    return helper(word1, word2, m, n);
}


class Solution {
public:
    int minDistance(string word1, string word2) {

        int R = word1.length();
        int C = word2.length();

        int dp[R+1][C+1];

        for ( int i = 0; i <= R; i++) {
            for ( int j = 0; j <= C; j++) {
                if ( i == 0 ) {
                    dp[i][j] = j;
                }else if ( j == 0 ) {
                    dp[i][j] = i;
                }else if ( word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }else {
                    dp[i][j] = 1 + min(dp[i-1][j-1],
                            min(dp[i][j-1], dp[i-1][j]));

                }

            }
        }
        return dp[R][C];

    }
};


int main() {

    string w1 = "horse";
    string w2 = "ros";

    Solution sol;

    std::cout << "\n Minimum distance" << minDistance(w1 , w2) << std::endl;
    std::cout << "\n Minimum distance" << sol.minDistance(w1 , w2) << std::endl;

}
