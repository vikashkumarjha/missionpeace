#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& h) {
        if ( h.empty()) return 0;
        int maxArea = 0;

        int l = 0;
        int r = h.size() - 1;
        while ( l < r) {
            maxArea = max(maxArea, (r - l) * min(h[l], h[r]));
            if ( h[l] < h[r]) {
                l++;
            }else {
                r--;
            }
        }
        return maxArea;
    }
};

int main()
{
    vector<int> h = {1,8,6,2,5,4,8,3,7};
    Solution s;
    int res = s.maxArea(h);
    cout << "\n The value of the result:" << res;
    return 0;
}
