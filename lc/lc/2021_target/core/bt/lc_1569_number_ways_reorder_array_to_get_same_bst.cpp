So, we can know that for a fixed root, the left subtree elements and the right subtree elements are also fixed.

We can find the left subtree elements which are all the elements that is smaller than root value, and right subtree elements which are greater than root value.

And in order to make it identical with original BST, we should keep the relative order in left subtree elements and in right subtree elements.

Assume the lenght of left subtree elements is left_len and right is right_len, they can change their absolute position but need to keep their relative position in either left subtree or right right subtree.

So as the subtree, so we use recursion.

Example

[3, 4, 5, 1, 2] // original array with root value is 3

[1, 2] // left sub-sequence, left_len = 2
[4, 5] // right sub-sequence, right_len = 2

// the left sub-sequence and right sub-sequence take 4 position, because left_len + right_len = 4

// keep relative order  in left sub-sequence and in right-sequence, but can change absolute position.
[1, 2, 4, 5]
[1, 4, 2, 5]
[1, 4, 5, 2]
[4, 1, 2, 5]
[4, 1, 5, 2]
[4, 5, 1, 2]
// number of permutation: 6

// in code, we use Pascal triangle to keep a table of permutations, so we can look up the table and get permutation result in O(1)
Code

class Solution {
public:
    int numOfWays(vector<int>& nums) {
        long long mod = 1e9 + 7;
		int n = nums.size();
        
		// Pascal triangle
        table.resize(n + 1);
        for(int i = 0; i < n + 1; ++i){
            table[i] = vector<long long>(i + 1, 1);
            for(int j = 1; j < i; ++j){
                table[i][j] = (table[i-1][j-1] + table[i-1][j]) % mod;
            }
        }
        
        long long ans = dfs(nums, mod);
        return ans % mod - 1;
    }
    
private:
    vector<vector<long long>> table;
    long long dfs(vector<int> &nums, long long mod){
        int n = nums.size();
        if(n <= 2) return 1;
        
		// find left sub-sequence elements and right sub-sequence elements
        vector<int> left, right;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] < nums[0]) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
		
		// recursion with left subtree and right subtree
        long long left_res = dfs(left, mod) % mod;
        long long right_res = dfs(right, mod) % mod;
		
		// look up table and multiple them together
		int left_len = left.size(), right_len = right.size();
        return (((table[n - 1][left_len] * left_res) % mod) * right_res) % mod;
    }
};
