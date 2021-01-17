/*
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

*/

#include "../../header.hpp"

class Solution {
public:
     int largestRectangleArea(vector<int> & heights) {
       
        heights.push_back(0);
        int  area=0;
        stack<int> stack;        
        for(int i=0;i<heights.size();++i){  
            //start calculation when u encounter less then the top.
            while(!stack.empty()&& heights[stack.top()]> heights[i]){
                int h=heights[stack.top()];
                stack.pop();
                int w = stack.empty()? i:i-1-stack.top();
                area=max(area,h*w ); 
            }
             stack.push(i);
        }
        
       return area; 
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())  return 0;
       
        int R = matrix.size();
        int C = matrix[0].size();
       
        vector<int> heights(C, 0);
       
        int maxArea = 0;
        for (int i = 0; i < R; i++) {
             for (int j = 0; j < C; j++) {            
                  if (matrix[i][j] == '0')
                      heights[j] = 0;
                  else
                      heights[j]++;
             }
           
             maxArea = max(maxArea, largestRectangleArea(heights));
        }
       
        return maxArea;
    }
};
