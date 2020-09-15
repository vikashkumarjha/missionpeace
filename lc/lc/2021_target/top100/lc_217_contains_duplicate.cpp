#include "../header.hpp"

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        vector<int> digits(11,0);
        for ( auto n : nums) {
            digits[n]++;
            if ( digits[n] > 1) return true;

        }
        return false;
    }
};

int main()
{
    vector<int> input = {1,2,3,4};
    Solution s;
    if (s.containsDuplicate(input)) {
        cout << "contains duplicate...";
    }else {
        cout << "contains no duplicate...";
    }    
    return 0;
}