/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool IsSquareAllTheSameValue(vector<vector<int>>& grid, int i_start, int j_start, int i_length, int j_length) {
        bool value = grid[i_start][j_start];
        for (int i = 0; i < i_length; ++i) {
            for (int j = 0; j < j_length; ++j) {
                if (grid[i_start + i][j_start + j] != value)
                    return false;
            }
        }
        return true;
    }
    Node* construct(vector<vector<int>>& grid, int i_start, int j_start, int i_length, int j_length) {
        bool is_const = IsSquareAllTheSameValue(grid, i_start, j_start, i_length, j_length);
        Node * newNode = new Node(grid[i_start][j_start], is_const, nullptr, nullptr, nullptr, nullptr);
        if (is_const)
            return newNode;
        int left_j_length = j_length / 2;
        int right_j_length = j_length - left_j_length;
        int top_i_length = i_length / 2;
        int bottom_i_length = i_length - top_i_length;
        int right_j_start = j_start + left_j_length;
        int bottom_i_start = i_start + top_i_length;
        newNode->topLeft     = construct(grid, i_start,        j_start,       top_i_length,    left_j_length);
        newNode->topRight    = construct(grid, i_start,        right_j_start, top_i_length,    right_j_length);
        newNode->bottomLeft  = construct(grid, bottom_i_start, j_start,       bottom_i_length, left_j_length);
        newNode->bottomRight = construct(grid, bottom_i_start, right_j_start, bottom_i_length, right_j_length);
        return newNode;
    }
    Node* construct(vector<vector<int>>& grid) {
        return construct(grid, 0, 0, grid.size(), grid[0].size());
    }
};
