#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


void bubble_sort(vector<int> &a) 
{
    for ( int i = 0; i < a.size() - 1; i++)
    {
        bool isSwapped = false;
        for ( int j = 0; j < a.size()- i- 1; j++)
        {
            if ( a[j] > a[j+1]) {
                isSwapped = true;
                swap(a[j], a[j+1]);
            }
        }
        if (!isSwapped) {
            break;
        }
    }
}

int main()
{
    vector<int> a = { 1, 10, 11, 99, 5, 100};
    bubble_sort(a);
    for_each(begin(a), end(a), [](int x){
        cout << x << " ";
    });

    return 0;

}