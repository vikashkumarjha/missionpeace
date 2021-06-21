/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
public:
    // constants for 4 directions
    const int up = 0;
    const int left = 1;
    const int down = 2;
    const int right = 3;
    
    // initally facing up
    int direction = up; 
    
    set<pair<int,int>> traversedSpots;
    
    void cleanRoom(Robot& robot) {
        Traverse(0,0,up,robot);
    }
    
    bool Traverse(int x, int y, int dir, Robot& robot)
    {
        if(!IsTraversed(x,y))
        {
            // traverse this spot
            if((x==0 && y==0) || MoveTo(dir,robot))
            {
                // clean
                robot.clean();
                
                // mark it as traversed
                MarkTraversed(x,y);
                
                // keep going further
                // top
                if(Traverse(x, y+1, up, robot))
                    MoveTo(down,robot);
                
                // left
                if(Traverse(x-1, y, left, robot))
                    MoveTo(right,robot);

                // bottom
                if(Traverse(x, y-1, down, robot))
                    MoveTo(up,robot);
                
                // right
                if(Traverse(x+1, y, right, robot))
                    MoveTo(left,robot);
                
                return true;
            }
        }
        
        return false;
    }
    
    bool MoveTo(int dir, Robot& robot)
    {   
        Face(dir,robot);
        return robot.move();
    }
    
    void Face(int dir, Robot& robot)
    {
        if(dir == direction)
            return;
        
        while(direction != dir)
        {
            robot.turnLeft();
            direction = (direction+1)%4;
        }
    }
    
    void MarkTraversed(int x, int y)
    {
        traversedSpots.insert({x,y});
    }
    
    bool IsTraversed(int x, int y)
    {
        return (traversedSpots.find({x,y}) != traversedSpots.end());
    }
};