/*
 * Alice has a hand of cards, given as an array of integers.
 *
 * Now she wants to rearrange the cards into groups so that each group is size
 * W, and consists of W consecutive cards.
 *
 * Return true if and only if she can.
 *
 *
 *
 *  Example 1:
 *
 *  Input: hand = [1,2,3,6,2,3,4,7,8], W = 3
 *  Output: true
 *  Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8].
 *
 *  */


/*
 * Count number of different cards to a map c
 * Loop from the smallest card number.
 * Everytime we meet a new card i, we cut off i - i + W - 1 from the counter.
 *
 * Time O(MlogM + MW), where M is the number of different cards.
 * */

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int, int> m;
        for (int i : hand) m[i]++;
        for (auto it : m)
            if (m[it.first] > 0)
                for (int i = W - 1; i >= 0; --i)
                    if ((m[it.first + i] -= m[it.first]) < 0)
                        return false;
        return true;

    }
};
