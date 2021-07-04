/*
 * Given two integers n and k, return all possible combinations of k numbers out
 * of the range [1, n]
 *
 * */

#include <iostream>
#include <vector>

using namespace std;

void combineHelper(int start, vector<int> &path, vector<vector<int>> &paths, int n, int k)
{
    if ( path.size() == k)
    {
        paths.push_back(path);
        return;
    }

    for ( int idx = start; idx <= n; idx++)
    {
        path.push_back(idx);
        combineHelper(idx+1, path, paths, n, k);
        path.pop_back();

    }
}



vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> paths;
    vector<int> path;
    combineHelper(1, path, paths, n, k );
    return paths;
}


int main()
{
    vector<vector<int>> r = combine(4,0);
    for ( auto row : r)
    {
        cout << "\n";
        for (auto c : row)
            cout << c << " ";
    }
    return 0;
}
