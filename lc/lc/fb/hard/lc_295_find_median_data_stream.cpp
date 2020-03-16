/*
 * Median is the middle value in an ordered integer list. If the size of the
 * list is even, there is no middle value. So the median is the mean of the two
 * middle value.
 *
 * For example,
 * [2,3,4], the median is 3
 *
 * [2,3], the median is (2 + 3) / 2 = 2.5
 *
 * Design a data structure that supports the following two operations:
 *
 * void addNum(int num) - Add a integer number from the data stream to the data
 * structure.
 * double findMedian() - Return the median of all elements so far.
 *
 *
 *  Example:
 *
 *  addNum(1)
 *  addNum(2)
 *  findMedian() -> 1.5
 *  addNum(3)
 *  findMedian() -> 2
 *
 *  */

#include "header.hpp"
using namespace std;



class MedianFinder {
public:
    /** initialize your data structure here. */
    int n = 0;
    multiset<int> ms;
    multiset<int> :: iterator iter;

    void addNum(int num) {
        if(n == 0) {
            ms.insert(num);
            iter = ms.begin();
            n++;
            return;
        }
        n++;
        ms.insert(num);
        if(n % 2 == 0) {
            if(num < *iter) {
                iter = prev(iter);
            }
        } else {
            if(num >= *iter) {
                iter = next(iter);
            }
        }

    }

    double findMedian() {
        if(n % 2 == 1) {
            return *iter;
        } else {
            return (double)(*iter+*next(iter)) / 2.0;
        }
    }
};
