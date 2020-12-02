/*


Given an integer array nums, design an algorithm to randomly shuffle the array.

Implement the Solution class:

Solution(int[] nums) Initializes the object with the integer array nums.
int[] reset() Resets the array to its original configuration and returns it.
int[] shuffle() Returns a random shuffling of the array.
 

Example 1:

Input
["Solution", "shuffle", "reset", "shuffle"]
[[[1, 2, 3]], [], [], []]
Output
[null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]

*/

class Solution {
public:
    vector<int> nums;
    vector<int> ran;
    Solution(vector<int>& nums) {
        this->nums = nums;
        ran = nums;
    }
	
    vector<int> reset() {
        return nums;
    }
	
    vector<int> shuffle() {
        int i1 = rand()%nums.size();
        int i2 = rand()%nums.size();
        swap(ran[i1], ran[i2]);
        return ran;
    }
};