#include <iostream>
#include <vector>

using namespace std;

int bsearch(vector<int> &a, int item, int low, int high) 
{
    if (high <= low)
        return (item > a[low])?  (low + 1): low; 

    int mid = (low + high)/2;

    if(item == a[mid]) 
        return mid+1; 

    if(item > a[mid]) 
        return bsearch(a, item, mid+1, high); 

    return bsearch(a, item, low, mid-1); 
}



void binary_insertion_sort(vector<int> &nums) {
   int n = nums.size(); 

   for ( int i = 1; i < n; i++) {
       int key = nums[i];
       int j = i - 1;
       auto pos = bsearch(nums, key, 0, j);
       // move all elements after insertPos
       while ( j >= pos) {
           nums[j+1] = nums[j];
           j--;
       }
       nums[j+1] = key;
   }

}



int main() {
    vector<int> v = { 100, 10, 12, 99, 55, 20, 1};
    binary_insertion_sort(v);
    for ( auto n : v) {
        std::cout <<  n << " ";
    }

    return 0;


}
