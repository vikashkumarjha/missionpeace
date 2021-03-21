/*
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]

*/

#include "header.hpp"

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     std::unordered_map<int,int> m;
        for ( auto n : nums ) {
                m[n]++;
        }
        std::priority_queue<std::pair<int,int>> pq;

        for ( auto it = m.begin(); it != m.end(); it++)
        {
                pq.push(std::make_pair(it->second,it->first));
        }
        int count = 0;
        std::vector<int> result;

        while ( !pq.empty()){
                auto it = pq.top();
                ++count;
                pq.pop();
                result.push_back(it.second);
                if ( count == k ) break;
        }
        return result;
    }
};

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, in k)
    {
        std::unordered_map<int, int> frequency;
        for (auto n : nums)
        {
            frequency[n]++;
        }
        std::vector<std::list<int>> bucket(nums.size() + 1, std::list<int>{});

        for (auto it = frequency.begin(); it != frequency.end(); it++)
        {
            bucket[it->second].push_back(it->first);
        }

        int count = 0;
        std::vector<int> result;
        for (int j = bucket.size() - 1; j >= 0 && count < k; j--)
        {
            if (bucket[j].size() > 0)
            {
                for (auto it = bucket[j].begin(); it != bucket[j].end(); it++)
                {
                    ++count;
                    result.push_back(*it);
                    if (count == k)
                        break;
                }
            }
        }

        return result;
    }
};