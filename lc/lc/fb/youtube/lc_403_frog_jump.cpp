//
//  lc_403_frog_jump.cpp
//  lc
//
//  Created by vikash kumar jha on 3/1/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//

/*

               9    (k + 1 == 5)
              /
             4 --8  (k == 4)
              \
               7    (k - 1 == 3)
        **********************************************

*/

#if 0

class Solution {
public:
    bool canCross(vector<int>& stones) {
        vector<set<int>> visit(stones.size(), set<int>());
        return dfs(stones, 0, 1, visit);
    }

    bool dfs(vector<int>& stones, int index, int units, vector<set<int>>& visit) {
        if (index == stones.size() - 1) return true;
        
        if (index >= stones.size()) return false;
        
        // if already visited return false;
        if (visit[index].count(units)) return false;
        
        // from current
        
        // we need to find if a stone exists at (currentPosition + new jumpsize)(currentPosition+newjumpsize),
        
        // for the particular unit size try to find till what stones we can reach.
        
        
        
        for (int i = index; i < stones.size() && stones[index] + units >= stones[i]; ++i)         {
            // frog must need to land on the last index.
            if (stones[index] + units == stones[i]) {
                if (units > 0 && dfs(stones, i, units - 1, visit)) return true;
                if (units > 0 && dfs(stones, i, units, visit)) return true;
                if (dfs(stones, i, units + 1, visit)) return true;
            }
        }
        // mark it visited.
        visit[index].insert(units);
        return false;
    }
};

#endif
