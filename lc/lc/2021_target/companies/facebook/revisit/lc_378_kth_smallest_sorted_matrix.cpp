class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
         int m = matrix.size(), n = matrix[0].size();
        priority_queue<int, vector<int>> pq;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pq.emplace(matrix[i][j]);
                if (pq.size() > k) {
                    pq.pop();
                }
            }
        }
        int result = pq.top();
        return result;
        
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
       int R = matrix.size();
    if ( R == 0 ) return INT_MAX;
    
    int C = matrix[0].size();
    int l = matrix[0][0];
    int r = matrix[R-1][C-1];
    
    while ( l <= r) {
        int m = l + ( r - l ) / 2;
        int count = 0;
        for ( int i = 0; i < R; i++) {
            int pos = upper_bound(matrix[i].begin(), matrix[i].end(), m) - matrix[i].begin();
            count += pos;
        }
        if (count < k ) {
            l = m + 1;
        }else {
            r = m - 1;
        }
        
        
    }
    return l;
        
    }
};