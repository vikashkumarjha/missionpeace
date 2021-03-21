/*
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/

class Solution {
public:
    int helper(int n, unordered_map<int, int>& cache){
        if (cache.count(n)){
            return cache[n];
        }else{
            int total = 0;
            for(int i = 1; i <= n; ++i){
                total += helper(i - 1, cache) * helper(n - i, cache);
            }
            cache[n] = total;
            return total;
        }
    }
    
    int numTrees(int n) {
        unordered_map<int, int> cache;
        cache[0] = 1;
        cache[1] = 1;
        return helper(n, cache);
    }
};