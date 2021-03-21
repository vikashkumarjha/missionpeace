/*
A frog is crossing a river. The river is divided into x units and at each unit there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

Given a list of stones' positions (in units) in sorted ascending order, determine if the frog is able to cross the river by landing on the last stone. Initially, the frog is on the first stone and assume the first jump must be 1 unit.

If the frog's last jump was k units, then its next jump must be either k - 1, k, or k + 1 units. Note that the frog can only jump in the forward direction.

Note:

The number of stones is ≥ 2 and is < 1,100.
Each stone's position will be a non-negative integer < 231.
The first stone's position is always 0.

*/

/*

               9    (k + 1 == 5)
              /
             4 --8  (k == 4)
              \ 
               7    (k - 1 == 3)
        **********************************************

*/

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