
/*
We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

(Here, the distance between two points on a plane is the Euclidean distance.)

You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

 

Example 1:

Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]
Explanation: 
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].

*/


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<int,int>> toSort;
        for ( auto p : points) {
            toSort.push_back(make_pair(p[0], p[1]));
        }
        
        sort(toSort.begin(), toSort.end(), []( auto &p1, auto &p2){
           return( ( p1.first * p1.first + p1.second * p1.second) < 
                   ( p2.first * p2.first + p2.second * p2.second) );
                   
        });
        
        vector<vector<int>> res;
        for ( int i = 0; i < K; i++) {
            res.push_back({toSort[i].first, toSort[i].second});
        }
        
        return res;
        
        
        
    }
};


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<>> pq;
        for(vector<int> point : points)
        {
            int dist = point[0]*point[0] + point[1] * point[1];
            pq.push(make_pair(dist, point));
        }
        vector<vector<int>> out;
        while(out.size() < K)
        {
            out.push_back(pq.top().second);
            pq.pop();
        }
        return out;
    }
};