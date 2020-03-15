/*
 * We have a set of items: the i-th item has value values[i] and label labels[i].

Then, we choose a subset S of these items, such that:

|S| <= num_wanted
For every label L, the number of items in S with label L is <= use_limit.
Return the largest possible sum of the subset S.



Example 1:

Input: values = [5,4,3,2,1], labels = [1,1,2,2,3], num_wanted = 3, use_limit = 1
Output: 9
Explanation: The subset chosen is the first, third, and fifth item.
Example 2:

Input: values = [5,4,3,2,1], labels = [1,3,3,3,2], num_wanted = 3, use_limit = 2
Output: 12
Explanation: The subset chosen is the first, second, and third item.
Example 3:

Input: values = [9,8,8,7,6], labels = [0,0,0,1,1], num_wanted = 3, use_limit = 1
Output: 16
Explanation: The subset chosen is the first and fourth item.

*/

/*Basically what the questions want is

pick number from values, and values picked should be as big as possibile
but based on the label, we can only pick num_limited values of the same label.
the algorithm is put all the values into a maxHeap, and each time we pick from the top, so this cam ensures we always get the largest possible result
we use another map to track how many values we picked from the same group
The time complexity will be O(nlogn)
space complexity is O(n)

*/
struct myComp {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> maxHeap;
        int n = values.size();
        for (int i = 0; i < n; ++i) {
            maxHeap.push({labels[i], values[i]});
        }

        int result = 0;
        unordered_map<int, int> used;
        int count = 0;
        while (count < num_wanted and !maxHeap.empty()) {
            pair<int, int> cur = maxHeap.top();
            maxHeap.pop();
            if (used[cur.first] < use_limit) {
                result += cur.second;
                used[cur.first] += 1;
                count += 1;
            }
        }
        return result;
    }
};
