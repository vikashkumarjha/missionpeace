#include "header.hpp"
using namespace std;


vector<int> spiralOrder(vector<vector<int>>& m) {
    if ( m.empty() ) return {};
    int top = 0;
    int bottom = m.size() - 1;

    int left = 0;
    int right = m[0].size() - 1;
    vector<int> result;

    while ( left <= right && top <= bottom) {
        // print the first row
        for ( int c = left; c <= right; c++) {
            result.push_back(m[top][c]);
        }
        // print the rightmost col
        for ( int r = top + 1; r <= bottom; r++) {
            result.push_back(m[r][right]);
        }
        // print the last row
        if ( top < bottom) {
            for ( int c = right - 1; c > left ; c--) {
                result.push_back(m[bottom][c]);
            }
        }

        // print the leftmost colum
        if ( left < right) {
            for ( int r = bottom - 1; r > top; r--) {
                result.push_back(m[r][left]);
            }
        }
        top++;
        left++;
        right--;
        bottom--;
    }
    return result;
}


int main() {
    vector<vector<int>> m= { { 1, 2, 3}, {4,5,6}, {7,8,9}};

    auto r = spiralOrder(m);
    for ( auto x : r) {
        std::cout << x << " ";
    }
}
