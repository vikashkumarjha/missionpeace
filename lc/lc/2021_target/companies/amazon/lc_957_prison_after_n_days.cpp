/*
here are 8 prison cells in a row, and each cell is either occupied or vacant.

Each day, whether the cell is occupied or vacant changes according to the following rules:

If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
Otherwise, it becomes vacant.
(Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.)

We describe the current state of the prison in the following way: cells[i] == 1 if the i-th cell is occupied, else cells[i] == 0.

Given the initial state of the prison, return the state of the prison after N days (and N such changes described above.)

 

Example 1:

Input: cells = [0,1,0,1,1,0,0,1], N = 7
Output: [0,0,1,1,0,0,0,0]
Explanation: 
The following table summarizes the state of the prison on each day:
Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
Day 7: [0, 0, 1, 1, 0, 0, 0, 0]

*/

class Solution {
public:
    void NextDay(const vector<int> &cells, vector<int> &next) {
        next[0] = 0;
        next.back() = 0;
        for (int i = 1; i < cells.size() - 1; ++i) {
            if (cells[i-1] == cells[i + 1])
                next[i] = 1;
            else
                next[i] = 0;
        }
        return;
    }
    struct VectorHash {
        std::size_t operator()(const vector<int>& k) const
        {
            return std::hash<int>()(k[0]) ^
                    (std::hash<int>()(k[1]) << 1) ^
                    (std::hash<int>()(k[2]) << 2) ^
                    (std::hash<int>()(k[3]) << 3) ^
                    (std::hash<int>()(k[4]) << 4) ^
                    (std::hash<int>()(k[5]) << 5) ^
                    (std::hash<int>()(k[6]) << 6) ^
                    (std::hash<int>()(k[7]) << 7);
        }
    };
    int FindCycleLength(vector<int> cells, int N) {
        unordered_set<vector<int>, VectorHash> us;
        us.insert(cells);
        vector<int> next = cells;
        int count = 1;
        for (int i = 0; i < N; ++i) {
            NextDay(cells, next);
            cells = next;
            if (us.count(cells) > 0)
                return count;
            us.insert(cells);
            ++count;
        }
        return count;
    }
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        if (N == 0)
            return cells;
        vector<int> next = cells;
        NextDay(cells, next);
        cells = next;
        --N;
        if (N == 0)
            return cells;
        
        int cycle_length = FindCycleLength(cells, N);
        N = N % cycle_length;
        for (int i = 0; i < N; ++i) {
            NextDay(cells, next);
            cells = next;
        }
        return cells;
    }
};