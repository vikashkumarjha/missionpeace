/*
Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a list of disjoint intervals.

For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:

[1, 1]
[1, 1], [3, 3]
[1, 1], [3, 3], [7, 7]
[1, 3], [7, 7]
[1, 3], [6, 7]

*/

class SummaryRanges {
    set<pair<int,int>> set0;
public:
    SummaryRanges() {}
    
    void addNum(int val) {
        auto iter = set0.lower_bound({val, 0});
        int left = val, right = val;
        
		// only two intervals can overlap with val, lower_bound and the one before lower_bound
		// check both and do possible merges
        if (iter != set0.begin()) {
            auto piter = prev(iter);
            if (piter->second >= val-1) {
                left = piter->first;
                right = max(piter->second, val);

                set0.erase(piter);
            }
        }
        
        if (iter != set0.end()) {
            if (iter->first <= val+1) {
                // left has been correctly set, it's either val, or piter->left
                right = iter->second;

                set0.erase(iter);
            }
        }
        
        set0.insert({left, right});
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (auto [start, end] : set0) {
            res.push_back({start, end});
        }
        return res;
    }
};
/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
