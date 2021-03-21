class Solution {
public:
	vector<vector<string>> solveNQueens(const int& n) {
		vector<vector<string>> result;
		vector<string> solution(n, string(n, '.'));
		solveNQueens(result, solution, 0, n);
		return result;
	}
private:
	void solveNQueens(vector<vector<string>>& result, vector<string>& solution, const int& row, const int& n) {
		if (row == n) {
			result.push_back(solution);
			return;
		}
		else {
			for (int i = 0; i < n; ++i) {
				if (isValid(row, i, solution, n)) {
					solution[row][i] = 'Q';
					solveNQueens(result, solution, row + 1, n);
					solution[row][i] = '.';
				}
			}
			return;
		}
	}
private:
	bool isValid(const int& row, const int& column, const vector<string>& solution, const int& n) {
		for (int i = 0; i < row; ++i) {
			if (solution[i][column] == 'Q')
				return false;
		}
		for (int i = row - 1, j = column - 1; i >= 0 && j >= 0; --i, --j) {
			if (solution[i][j] == 'Q')
				return false;
		}
		for (int i = row - 1, j = column + 1; i >= 0 && j <= n - 1; --i, ++j) {
			if (solution[i][j] == 'Q')
				return false;
		}
		return true;
	}
};