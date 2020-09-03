#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for ( int i = 0; i < n; i++) {
            for ( int j = i + 1; j < n; j++) {
                if ( nums[i] + nums[j] == target) {
                    return vector<int> {i,j};
                }
            }
        }

        return {};
        
    }
};

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        int n = nums.size();
        for ( int i = 0; i < n; i++) {
            int complment = target - nums[i];
            if ( m.count(complment) && m[complment] != i ) {
                return {i, m[complment]};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};



int main()
{
    vector<int> n = {2,7,11,15};
    Solution s;
    auto r = s.twoSum(n, 9);
    std::for_each(r.begin(), r.end(), [](int x){ cout << x << " ";});
    std::cout << "\n";
    
    Solution s2;
    auto r2 = s2.twoSum(n, 9);
    std::for_each(r2.begin(), r2.end(), [](int x){ cout << x << " ";});

    return 0;

}