/*
Consider a 1D overlap (Interval problem).
     For an overlap to occur necessary condition is
     
             x3,y2          x4,y2
               |--------------|
     |--------------|
     x1,y1         x2,y1
              
     x1 < x3 < x2  && x3 < x2 < x4 
     
     Or simplified - x1 < x4 && x3 < x2
     For 2D case use 1D conditions for both X and Y axes
     
     Case-1: Rec2 intersects with Rec1 on top right corner

               ____________________x4,y4
              |                   |
       _______|______x2,y2        |
      |       |______|____________|
      |      x3,y3   |
      |______________|
     x1,y1
              
     Case-2: Rec2 intersects with Rec1 on top left corner
       ___________________  x4,y4
      |                   |
      |            _______|____________x2,y2
      |___________|_______|           |
    x3,y3         |                   | 
                  |___________________|
                x1,y1

     Case-3: Rec2 intersects with Rec1 on bottom left corner
     
               ____________________x2,y2
              |                   |
       _______|______x4,y4        |
      |       |______|____________|
      |      x1,y1   |
      |______________|
     x3,y3
              
     Case-4: Rec2 intersects with Rec1 on bottom right corner
     
       ___________________  x2,y2
      |                   |
      |            _______|____________x4,y4
      |___________|_______|           |
    x1,y1         |                   | 
                  |___________________|
                x3,y3
    
    bool case1 = (x1 < x4 && x3 < x2 && y1 < y4 && y3 < y2); //top right intersection
    bool case2 = (x3 < x2 && x1 < x4 && y1 < y4 && y3 < y2); //top left intersection
    bool case3 = (x3 < x2 && x1 < x4 && y3 < y2 && y4 < y1); //bottom left intersection
    bool case4 = (x1 < x4 && x3 < x2 && y3 < y2 && y4 < y1); //bottom right intersection
    
    if you look carefully in all cases we have same 4 comparisons

    */


class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        
        int x1 = rec1[0];
        int y1 = rec1[1];
        int x2= rec1[2];
        int y2= rec1[3];

        int x3 = rec2[0];
        int y3 = rec2[1];
        int x4 = rec2[2];
        int y4 = rec2[3];


        return (x1 < x4 && x3 < x2 && y1 < y4 && y3 < y2);
        
    }
};