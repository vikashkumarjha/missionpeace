#include "header.hpp"
using namespace std;

/**
 *
Gven two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]}

*/


vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    set<int> s1(nums1.begin(), nums1.end());;
    set<int> s2(nums2.begin(),nums2.end());
    vector<int> result;


    for ( auto n : s1) {
        if ( s2.count(n)) {
            result.emplace_back(n);
        }
    }
    return result;

}

int main()
{
    vector<int> x = { 1, 2, 2,1};
    vector<int> y = { 2, 2};
    vector<int> r = intersection(x,y);
    std::for_each(r.begin(), r.end(), [](int x) {
            std::cout << x << " ";
     });
}
