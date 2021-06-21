class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
      const int row = matrix.size();
    if (0 == row) return 0;
    const int col = matrix[0].size();
    vector<vector<int>> ones(row, vector<int>(col+1, 0));
    for (int i = 0; i < row; i++) 
     for (int j = 0; j < col; j++) {
          if (matrix[i][j] == '1') {
              ones[i][j] = 1 + (i > 0 ? ones[i-1][j] : 0);
          }
     }
     
        
        
        
     int i = 0, max_a = 0;
     for (i; i < row; i++) {
         stack<int> stk;
         vector<int> cur = ones[i];
         int idx = 0;
         while (idx < cur.size()) {
             if (stk.empty() || cur[idx] >= cur[stk.top()]) {
                 stk.push(idx++);
             } else {
                int h = stk.top();
                stk.pop();
                max_a = max(max_a, cur[h] *(stk.empty() ? idx : idx - stk.top() - 1));
             }
         }
     }
     return max_a;
    
    }
};