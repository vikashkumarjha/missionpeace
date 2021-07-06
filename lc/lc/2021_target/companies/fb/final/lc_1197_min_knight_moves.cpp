/*
 * In an infinite chess board with coordinates from -infinity to +infinity, you have a knight at square [0, 0].

A knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.

*/

class Solution {
public:
    int minKnightMoves(int x, int y) {
        if(!x && !y) return 0;
        vector<pair<int,int>> dir={{-1,-2},{-2,-1},{-2,1},{-1,2},{1,-2},
            {2,-1},{2,1},{1,2}};
        queue<pair<int,int>> q;
        unordered_set<string> s;
        q.push({0,0});
        double val=sqrt(x*x+y*y);
        int res=0;
        while(!q.empty()){
            int size=q.size();
            res++;
            for(int i=0;i<size;i++){
                auto cur=q.front();
                q.pop();
                for(auto d:dir){
                    int X=d.first+cur.first;
                    int Y=d.second+cur.second;
                    if(X==x && Y==y) return res;
                    string str=to_string(X)+','+to_string(Y);
                    double val2=sqrt((X-x)*(X-x)+(Y-y)*(Y-y));
                    if(!s.count(str) && (val2<val || val<2)){
                        val=val2;
                        q.push({X,Y});
                        s.insert(str);
                    }
                }
            }
        }
        return res;
    }
};
