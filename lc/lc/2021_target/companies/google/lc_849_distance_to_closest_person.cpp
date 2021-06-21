/*
You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed).

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to the closest person.
*/


class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int> left(n,n);
        vector<int> right(n,n);
        
        
        
        for (int i = 0; i < n; i++)
        {
            if ( seats[i] == 1) {
                left[i] = 0;
            }
            
            else if (i > 0 ) {
                left[i] = left[i-1] + 1;
            }
            
        }
        
      
        
        for (int i = n-1; i >= 0; i--)
        {
            if (seats[i] == 1) {
                right[i] = 0;
            }
            else if ( i < n - 1) {
                right[i] = right[i+1] + 1;
            }
            
        }
        
        
        int res = 0;
        
        for (int i = 0; i < n; ++i)
            if (seats[i] == 0)
                res = max(res, min(left[i], right[i]));
        
        return res;
        
    }
};


int maxDistToClosest(vector<int> seats) {
        int res = 0, n = seats.size(), last = -1;
        for (int i = 0; i < n; ++i) {
            if (seats[i] == 1) {
                res = last < 0 ? i : max(res, (i - last) / 2);
                last = i;
            }
        }
        res = max(res, n - last - 1);
        return res;
    }