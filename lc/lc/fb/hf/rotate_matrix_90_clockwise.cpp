#include "header.hpp"
using namespace std;


void rotate(vector<vector<int>> & m) {
    if ( m.empty()) return;
    int N = m.size();

    for ( int r = 0; r < N/2; r++) {
        for ( int c = r; c < N - r - 1; c++) {
            int temp = m[r][c];
            m[r][c] = m[N-1-r][c];
            m[N-1-r][c] = m[N-1-r][N-1-c];
            m[N-1-r][N-1-c] = m[c][N-1-r];
            m[c][N-1-r] = temp;
        }
    }


}
