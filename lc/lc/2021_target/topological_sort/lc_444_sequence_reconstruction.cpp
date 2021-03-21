
/*

Check whether the original sequence org can be uniquely reconstructed from the sequences in seqs. The org sequence is a permutation of the integers from 1 to n, with 1 ≤ n ≤ 104. Reconstruction means building a shortest common supersequence of the sequences in seqs (i.e., a shortest sequence so that all sequences in seqs are subsequences of it). Determine whether there is only one sequence that can be reconstructed from seqs and it is the org sequence.

 

Example 1:

Input: org = [1,2,3], seqs = [[1,2],[1,3]]
Output: false
Explanation: [1,2,3] is not the only one sequence that can be reconstructed, because [1,3,2] is also a valid sequence that can be reconstructed.
Example 2:

Input: org = [1,2,3], seqs = [[1,2]]
Output: false
Explanation: The reconstructed sequence can only be [1,2].


*/



// Input: org = [4,1,5,2,6,3], seqs = [[5,2,6,3],[4,1,5,2]]
//  5 --> 2 ---> 6 ---> 3
//  4 --> 1 ---> 5 ---> 2
//  4 --> 1 ---> 5 ---> 2 ---> 6 ---> 3

#include "header.hpp"


class Solution {
public:
    // Here Each Number in the Seq represent Node in the Graph.
    //   Seq[i] ---> Seq[i + 1] is an Edge.
    //   Use Toplogical Sort to check All Nodes are traversed only once in Org Seq order

    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        unordered_map<int, vector<int>> dag;
        unordered_map<int, int> indegree;
       
        for (const auto & seq : seqs) {
            if (seq.size())
                indegree.insert(make_pair(seq[0], 0));
           
            for (int i = 0; i + 1 < seq.size(); i++) {
                dag[seq[i]].push_back(seq[i + 1]);
                indegree[seq[i + 1]]++;
            }
        }
       
        // Here Its lead to Multiple Starting Point -- Its a Flaw
        queue<int> q;
        for (auto p : indegree)
            if (p.second == 0 && org[0] == p.first)
                q.push(p.first);
       
        int idx = 0;
        while (!q.empty()) {
            int x = q.front(); q.pop();
            if (!q.empty() || x != org[idx++])
                return false;
           
            for (auto x1 : dag[x])
                if (--indegree[x1] == 0)
                    q.push(x1);
        }
       
        if (idx != indegree.size() || idx != org.size())
            return false;
       
        return true;
    }
};