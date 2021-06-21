

/*
Edge case 1: all three stones are next to each other (z - x == 2). Return {0, 0}.
Edge case 2: two stones are next to each other, or there is only one space in between. Minimum moves is 1.

Otherwise; minimum moves are 2, maximum - z - x - 2.

So the position of the middle stone (y) only matters for the minimum moves.
*/


class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
          vector<int> s = { a, b, c };
  sort(begin(s), end(s));
  if (s[2] - s[0] == 2) return { 0, 0 };
  return { min(s[1] - s[0], s[2] - s[1]) <= 2 ? 1 : 2, s[2] - s[0] - 2 };
        
    }
};