
/*
A bus has n stops numbered from 0 to n - 1 that form a circle. We know the distance between all pairs of neighboring stops where distance[i] is the distance between the stops number i and (i + 1) % n.

The bus goes along both directions i.e. clockwise and counterclockwise.

Return the shortest distance between the given start and destination stops.

*/

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int r1 = 0;
        int r2 = 0;
        int N = distance.size();
        
        for (int i = start; i != destination; i = (i + 1) % N) {
            r1 += distance[i];
        }
        
        for (int i = destination; i != start; i = (i + 1) % N) {
            r2 += distance[i];
        }
        
        return min(r1, r2);
        
        
    }
};