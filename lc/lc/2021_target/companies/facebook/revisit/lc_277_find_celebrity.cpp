

/*
You are given a helper function bool knows(a, b) 
which tells you whether A knows B. Implement a function 
int findCelebrity(n). There will be exactly one celebrity 
if he/she is in the party. Return the celebrity's label 
if there is a celebrity in the party. 
If there is no celebrity, return -1.


*/
class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0;
        for ( int i = 1; i < n; i++) {
            if ( !knows(i, candidate)){
                candidate = i;
            }
        }
        
        for ( int i = 0; i < n; i++) {
            if ( candidate == i) continue;
            
            if ( knows(candidate,i) or  !knows(i, candidate)) return -1;
            
        }
        
        return candidate;
       
    }
};