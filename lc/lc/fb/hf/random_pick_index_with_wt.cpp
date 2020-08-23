/*
Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index in proportion to its weight.

Note:

1 <= w.length <= 10000
1 <= w[i] <= 10^5
pickIndex will be called at most 10000 times.
Example 1:

Input: 
["Solution","pickIndex"]
[[[1]],[]]
Output: [null,0]

*/

class Solution {
public:
    Solution(vector<int>& w) {
        presum_.resize(w.size(), 0);
        presum_[0] = w[0];
        for (int i = 1; i < w.size(); ++ i) {
            presum_[i] = presum_[i-1] + w[i];
        }
    }
    
    int pickIndex() {
        int value = random() % presum_.back();
        auto iter = upper_bound(presum_.begin(), presum_.end(), value);
        return iter - presum_.begin();
    }
    
private:
    vector<int> presum_;
};
