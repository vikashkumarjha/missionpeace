/*
Design and implement an iterator to flatten a 2d vector. It should support the following operations: next and hasNext.

 

Example:

Vector2D iterator = new Vector2D([[1,2],[3],[4]]);

iterator.next(); // return 1
iterator.next(); // return 2
iterator.next(); // return 3
iterator.hasNext(); // return true
iterator.hasNext(); // return true
iterator.next(); // return 4
iterator.hasNext(); // return false

*/
#include "../header.hpp"

class Vector2D {
public:
    Vector2D(vector<vector<int>>& v) {
        for (auto r : v) {
            for ( auto c : r) {
                data.push_back(c);
            } 
        }
        pos = 0;
    }
    
    int next() {
        if (!hasNext()) return INT_MAX;
            int result = data[pos];
            pos++;
            return result;
     }
    
    bool hasNext() {
        return pos < data.size();    
    }
  private:
    vector<int> data;
    int pos;

};

