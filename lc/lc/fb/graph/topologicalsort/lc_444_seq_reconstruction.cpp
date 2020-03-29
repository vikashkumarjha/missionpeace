
/*
Check whether the original sequence org can be uniquely reconstructed from the sequences in seqs. The org sequence is a permutation of the integers from 1 to n, with 1 ≤ n ≤ 104. Reconstruction means building a shortest common supersequence of the sequences in seqs (i.e., a shortest sequence so that all sequences in seqs are subsequences of it). Determine whether there is only one sequence that can be reconstructed from seqs and it is the org sequence.

Example 1:

Input:
org: [1,2,3], seqs: [[1,2],[1,3]]

Output:
false

Explanation:
[1,2,3] is not the only one sequence that can be reconstructed, because [1,3,2] is also a valid sequence that can be reconstructed.

*/

class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        unordered_map<int, vector<int>> dag;
        unordered_map<int, int> indegree;
        for (const auto & seq : seqs)
        {
            if (seq.size())
                indegree[seq[0]];//make sure 0 is explicitly stored.
            for (int i = 0; i < (int)seq.size() - 1; ++ i)
            {
                dag[seq[i]].push_back(seq[i + 1]);
                indegree[seq[i + 1]]++;
            }
        }
        queue<int> numq;
        for (auto p : indegree)
            if (p.second == 0)
                numq.push(p.first);
        int count = 0;
        while(!numq.empty())
        {
            int num = numq.front();
            numq.pop();
            if (!numq.empty() || num != org[count ++])
                return false;
            for (auto n : dag[num])
                if (--indegree[n] == 0)
                    numq.push(n);
        }
        if (count != indegree.size() || count != org.size())
            return false;
        return true;
    }
};