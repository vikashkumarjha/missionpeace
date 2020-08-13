#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> m;
    for ( int i = 0; i < nums.size();i++) {
       auto complement = target - nums[i];
       if (m.count(complement)) {
           return {i, m[complement]};
       }
       m[nums[i]] = i;
    }
    return {};
}

int main() {
    vector<int> nums = { 2, 7, 11, 15};
    vector<int> result = twoSum(nums, 9);
    for ( auto r : result) {
        std::cout << r << " ";
    }
    return 0;
}
