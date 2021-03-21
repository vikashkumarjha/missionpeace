/*
Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

Example 1:

Input: "aabb"
Output: ["abba", "baab"]
Example 2:

Input: "abc"
Output: []

*/

#include "../header.hpp"


class Solution {
private:
    void dfs(int counts[], int l, int r, string& result, vector<string>& results) {
        if (l > r) {
            results.push_back(result);
            return;
        }
        for (int i = 0; i != 128; ++i) {
            if (l < r && counts[i] < 2) continue;
            if (l == r && counts[i] == 0) continue;
            result[l] = result[r] = i;
            counts[i] -= 2;
            dfs(counts, l + 1, r - 1, result, results);
            counts[i] += 2;
        }
    }
public:
    vector<string> generatePalindromes(string s) {
        int counts[128] = {0}, odds = 0;
        for (char c : s) counts[c]++;
        for (int i = 0; i != 128; ++i) odds += (counts[i] & 1);
        if (odds > 1) return vector<string>();
        
        string result(s.size(), ' ');
        vector<string> results;
        dfs(counts, 0, (int)s.size() - 1, result, results);
        return results;
    }
};