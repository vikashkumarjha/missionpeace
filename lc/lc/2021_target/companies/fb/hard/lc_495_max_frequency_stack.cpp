/*
 * Implement FreqStack, a class which simulates the operation of a stack-like data structure.

FreqStack has two functions:

push(int x), which pushes an integer x onto the stack.
pop(), which removes and returns the most frequent element in the stack.
If there is a tie for most frequent element, the element closest to the top of the stack is removed and returned.


Input: 
["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
[[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
Output: [null,null,null,null,null,null,null,5,7,5,4]
Explanation:
After making six .push operations, the stack is [5,7,5,7,4,5] from bottom to top.  Then:

pop() -> returns 5, as 5 is the most frequent.
The stack becomes [5,7,5,7,4].

pop() -> returns 7, as 5 and 7 is the most frequent, but 7 is closest to the top.
The stack becomes [5,7,5,4].

pop() -> returns 5.
The stack becomes [5,7,4].


*/

/*
 * thought process
 * Actually, as an implementation level detail, if x has frequency f, then we'll have x in all group[i] (i <= f), not just the top. This is because each group[i] will store information related to the ith copy of x.

Afterwards, our goal is just to maintain freq, group, and maxfreq as described above.

*/

#include "header.hpp"
using namespace std;

class FreqStack {
private:
    unordered_map<int , stack<int>> group;
    unordered_map<int, int> freq; // frequency map to track the current frequecy
    int maxFrequency;

public:

    FreqStack() {
        maxFrequency = 0;
    }

    void push(int x) {
        freq[x]++;
        group[freq[x]].push(x);
        maxFrequency = max(maxFrequency, freq[x]);
    }

    int pop() {
        int res = group[maxFrequency].top();
        group[maxFrequency].pop();
        if ( group[maxFrequency].size() == 0) {
            --maxFrequency;
        }
        freq[res]--;
        return res;
    }
};


