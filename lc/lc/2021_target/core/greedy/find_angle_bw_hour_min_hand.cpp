#include <iostream>
using namespace std;
 
// Function to compute the angle between the hour and minute hand
int findAngle(int hour, int min)
{
    // find the position of the hour's hand
    int h = (hour * 360) / 12 + (min * 360) / (12 * 60);
 
    // find the position of the minute's hand
    int m = (min * 360) / (60);
 
    // calculate the angle difference
    int angle = abs(h - m);
 
    // consider the shorter angle and return it
    if (angle > 180) {
        angle = 360 - angle;
    }
 
    return angle;
}
 
// Clock Angle Problem
int main()
{
    int hour = 5;
    int min = 30;
 
    cout << findAngle(hour, min);
 
    return 0;
}





