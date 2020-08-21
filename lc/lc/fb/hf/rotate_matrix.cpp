

//clock wise

class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        if ( a.empty()) return;
    int N = a.size();

    // Traverse each cycle 
    for (int i = 0; i < N / 2; i++) { 
        for (int j = i; j < N - i - 1; j++) { 
  
            // Swap elements of each cycle 
            // in clockwise direction 
            int temp = a[i][j]; 
            a[i][j] = a[N - 1 - j][i]; 
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j]; 
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i]; 
            a[j][N - 1 - i] = temp; 
        } 
    } 
        
    }
};


//anticlock wise

void rotateMatrix(int mat[][N]) 
{ 
    // Consider all squares one by one 
    for (int x = 0; x < N / 2; x++) { 
        // Consider elements in group of 4 in 
        // current square 
        for (int y = x; y < N - x - 1; y++) { 
            // store current cell in temp variable 
            int temp = mat[x][y]; 
  
            // move values from right to top 
            mat[x][y] = mat[y][N - 1 - x]; 
  
            // move values from bottom to right 
            mat[y][N - 1 - x] = mat[N - 1 - x][N - 1 - y]; 
  
            // move values from left to bottom 
            mat[N - 1 - x][N - 1 - y] = mat[N - 1 - y][x]; 
  
            // assign temp to left 
            mat[N - 1 - y][x] = temp; 
        } 
    } 
} 
  