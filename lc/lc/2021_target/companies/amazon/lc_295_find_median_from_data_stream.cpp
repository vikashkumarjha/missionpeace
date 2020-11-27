/*
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

For example,
[2,3,4], the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.

*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>

using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        _data.push_back(num);        
    }
    
    double findMedian() {
        sort(begin(_data), end(_data));
        int n = _data.size();
        
        if ( n & 1) {
            return _data[n/2];
        }else {
            return (_data[n/2 - 1]  + _data[n/2]) * 0.5;
        }
    }

  private:
  vector<int> _data;  
};

class MedianFinder2 {
public:
    /** initialize your data structure here. */
    MedianFinder2() {
        
    }
    
    void addNum(int num) {
            if ( _data.empty()) {
                _data.push_back(num);
            }else {
                _data.insert(lower_bound(_data.begin(), _data.end(), num), num);
            }
    }
    
    double findMedian() { 
        int n = _data.size();
        if ( n & 1) {
            return _data[n/2];
        }else {
            return (_data[n/2 - 1]  + _data[n/2]) * 0.5;
        }
        
    }
    private:
    vector<int> _data;

};

/*
Two iterators/pointers lo_median and hi_median, which iterate over the data multiset.

While adding a number num, three cases arise:

The container is currently empty. Hence we simply insert num and set both pointers to point to this element.

The container currently holds an odd number of elements. This means that both the pointers currently point to the same element.

If num is not equal to the current median element, then num goes on either side of it. Whichever side it goes, 
the size of that part increases and hence the corresponding pointer is updated. For example, if num is less than the median element,
 the size of the lesser half of input increases by 11 on inserting num. Thus it makes sense to decrement lo_median.
If num is equal to the current median element, then the action taken is dependent on how num is inserted into data. 
NOTE: In our given C++ code example, std::multiset::insert inserts an element after all elements of equal value. Hence we increment hi_median.
The container currently holds an even number of elements. This means that the pointers currently point to consecutive elements.

If num is a number between both median elements, then num becomes the new median. Both pointers must point to it.
Otherwise, num increases the size of either the lesser or higher half of the input. We update the pointers accordingly. It is important to remember that both the pointers must point to the same element now.
Finding the median is easy! It is simply the mean of the elements pointed to by the two pointers lo_median and hi_median.



*/

class MedianFinder3 {
    multiset<int> data;
    multiset<int>::iterator lo_median, hi_median;

public:
    MedianFinder3()
        : lo_median(data.end())
        , hi_median(data.end())
    {
    }

    void addNum(int num)
    {
        const size_t n = data.size();   // store previous size

        data.insert(num);               // insert into multiset

        if (!n) {
            // no elements before, one element now
            lo_median = hi_median = data.begin();
        }
        else if (n & 1) {
            // odd size before (i.e. lo == hi), even size now (i.e. hi = lo + 1)

            if (num < *lo_median)       // num < lo
                lo_median--;
            else                        // num >= hi
                hi_median++;            // insertion at end of equal range
        }
        else {
            // even size before (i.e. hi = lo + 1), odd size now (i.e. lo == hi)

            if (num > *lo_median && num < *hi_median) {
                lo_median++;                    // num in between lo and hi
                hi_median--;
            }
            else if (num >= *hi_median)         // num inserted after hi
                lo_median++;
            else                                // num <= lo < hi
                lo_median = --hi_median;        // insertion at end of equal range spoils lo
        }
    }

    double findMedian()
    {
        return ((double) *lo_median + *hi_median) * 0.5;
    }
};









int main()
{

    MedianFinder sol;
    MedianFinder2 sol2;

    for ( int i = 1; i <= 10; i++) {
        sol.addNum(i);
        sol2.addNum(i);
    }


    auto r = sol.findMedian();
    cout << "\n The result:" << r;

    r = sol2.findMedian();
    cout << "\n The result:" << r;
    return 0;


}