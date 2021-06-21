You are given an array of positive integers w where w[i] describes the weight of ith index (0-indexed).

We need to call the function pickIndex() which randomly returns an integer in the range [0, w.length - 1]. pickIndex() should return the integer proportional to its weight in the w array. For example, for w = [1, 3], the probability of picking the index 0 is 1 / (1 + 3) = 0.25 (i.e 25%) while the probability of picking the index 1 is 3 / (1 + 3) = 0.75 (i.e 75%).

More formally, the probability of picking index i is w[i] / sum(w).

 

Example 1:

Input
["Solution","pickIndex"]
[[[1]],[]]
Output
[null,0]

Explanation
Solution solution = new Solution([1]);
solution.pickIndex(); // return 0. Since there is only one single element on the array the only option is to return the first element.


class Solution {
public:
    map<int,int,greater<int>> m;
    int sum = 0;
    Solution(vector<int> w) {
        m[0] = 0;
        for(int i=0;i<w.size()-1;i++){
            sum+=w[i];
            m[sum] = i+1;
        }
        sum += w.back();
    }
    
    int pickIndex() {
        return m.lower_bound(rand()%sum)->second;
    }
};
