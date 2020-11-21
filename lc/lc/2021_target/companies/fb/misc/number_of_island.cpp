//
//  number_of_island.cpp
//  finishline
//
//  Created by vikash kumar jha on 10/24/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

#include <stdio.h>
#include<vector>
#include<iostream>
using namespace std;

// lets have a matrix of characters 1 and zero...

void dfs(vector<vector<char>> &m , vector<vector<bool>> &isVisited, int r, int c){
    
    int maxRow = static_cast<int>(m.size());
    int maxCol = static_cast<int>(m[0].size());
    isVisited[r][c] = true;
    
    if ( r - 1 >= 0 && !isVisited[r-1][c] && m[r-1][c] == '1' ){
        dfs(m, isVisited, r-1, c);
    }
    if ( r + 1 < maxRow && !isVisited[r+1][c] && m[r+1][c] == '1' ){
        dfs(m, isVisited, r+1, c);
    }
    if ( c -1  >= 0 && !isVisited[r][c-1] && m[r][c-1] == '1' ){
        dfs(m, isVisited, r, c-1);
    }
    if ( c+1 < maxCol && !isVisited[r][c+1] && m[r][c+1] == '1' ){
        dfs(m, isVisited, r, c+1);
    }
    
}



void main_no_islands()
{
    vector<vector<char>> m = {
        {'1', '0', '0', '1'},
        {'1', '0', '0', '0'},
        {'0', '0', '1', '1'},
        {'0', '0', '1', '1'},
        
    };
    
    vector<vector<bool>> isVisited(m.size(), vector<bool>(m[0].size(),false));
    
   
    int result = 0;
    
    for (int i = 0; i < m.size(); i++){
        for ( int j = 0; j < m[0].size(); j++){
            if ( m[i][j] == '1' && !isVisited[i][j]){
                result++;
                dfs(m,isVisited, i, j);
                
            }
        }
    }
    std::cout << "The number of islands" << result;
    
    
    
}
