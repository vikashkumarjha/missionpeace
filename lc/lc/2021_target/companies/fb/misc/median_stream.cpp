//
//  median_stream.cpp
//  finishline
//
//  Created by vikash kumar jha on 10/30/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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
        std::sort(_data.begin(), _data.end());
        int n = static_cast<int>(_data.size());
        
        double result = ( n & 1) ? _data[n/2] : (_data[n/2-1] + _data [n/2]) * 0.5;
        return result;
        
        
        
    }
private:
    vector<double> _data;
};



class MedianFinder2 {
    vector<int> store; // resize-able container

public:
    // Adds a number into the data structure.
    void addNum(int num)
    {
        if (store.empty())
            store.push_back(num);
        else
            store.insert(lower_bound(store.begin(), store.end(), num), num);     // binary search and insertion combined
    }

    // Returns the median of current data stream
    double findMedian()
    {
        int n = static_cast<int>(store.size());
        return n & 1 ? store[n / 2] : (store[n / 2 - 1] + store[n / 2]) * 0.5;
    }
};

/*
 Adding a number num:

 Add num to max-heap lo. Since lo received a new element, we must do a balancing step for hi. So remove the largest element from lo and offer it to hi.
 The min-heap hi might end holding more elements than the max-heap lo, after the previous operation. We fix that by removing the smallest element from hi and offering it to lo.
 The above step ensures that we do not disturb the nice little size property we just mentioned.

 A little example will clear this up! Say we take input from the stream [41, 35, 62, 5, 97, 108]. The run-though of the algorithm looks like this:

 Adding number 41
 MaxHeap lo: [41]           // MaxHeap stores the largest value at the top (index 0)
 MinHeap hi: []             // MinHeap stores the smallest value at the top (index 0)
 Median is 41
 =======================
 Adding number 35
 MaxHeap lo: [35]
 MinHeap hi: [41]
 Median is 38
 =======================
 Adding number 62
 MaxHeap lo: [41, 35]
 MinHeap hi: [62]
 Median is 41
 =======================
 Adding number 4
 MaxHeap lo: [35, 4]
 MinHeap hi: [41, 62]
 Median is 38
 =======================
 Adding number 97
 MaxHeap lo: [41, 35, 4]
 MinHeap hi: [62, 97]
 Median is 41
 =======================
 Adding number 108
 MaxHeap lo: [41, 35, 4]
 MinHeap hi: [62, 97, 108]
 Median is 51.5
 */

class MedianFinder3 {
    priority_queue<int> lo;                              // max heap
    priority_queue<int, vector<int>, greater<int>> hi;   // min heap

public:
    // Adds a number into the data structure.
    void addNum(int num)
    {
        lo.push(num);                                    // Add to max heap

        hi.push(lo.top());                               // balancing step
        lo.pop();

        if (lo.size() < hi.size()) {                     // maintain size property
            lo.push(hi.top());
            hi.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian()
    {
        return lo.size() > hi.size() ? (double) lo.top() : (lo.top() + hi.top()) * 0.5;
    }
};

/*
 Approach 4: Multiset and Two Pointers
 Intuition

 Self-balancing Binary Search Trees (like an AVL Tree) have some very interesting properties. They maintain the tree's height to a logarithmic bound. Thus inserting a new element has reasonably good time performance. The median always winds up in the root of the tree and/or one of its children. Solving this problem using the same approach as Approach 3 but using a Self-balancing BST seems like a good choice. Except the fact that implementing such a tree is not trivial and prone to errors.

 Why reinvent the wheel? Most languages implement a multiset class which emulates such behavior. The only problem remains keeping track of the median elements. That is easily solved with pointers! 2

 We maintain two pointers: one for the lower median element and the other for the higher median element. When the total number of elements is odd, both the pointers point to the same median element (since there is only one median in this case). When the number of elements is even, the pointers point to two consecutive elements, whose mean is the representative median of the input.

 Algorithm

 Two iterators/pointers lo_median and hi_median, which iterate over the data multiset.

 While adding a number num, three cases arise:

 The container is currently empty. Hence we simply insert num and set both pointers to point to this element.
 The container currently holds an odd number of elements. This means that both the pointers currently point to the same element.

 If num is not equal to the current median element, then num goes on either side of it. Whichever side it goes, the size of that part increases and hence the corresponding pointer is updated. For example, if num is less than the median element, the size of the lesser half of input increases by 11 on inserting num. Thus it makes sense to decrement lo_median.
 If num is equal to the current median element, then the action taken is dependent on how num is inserted into data. NOTE: In our given C++ code example, std::multiset::insert inserts an element after all elements of equal value. Hence we increment hi_median.
 The container currently holds an even number of elements. This means that the pointers currently point to consecutive elements.

 If num is a number between both median elements, then num becomes the new median. Both pointers must point to it.
 Otherwise, num increases the size of either the lesser or higher half of the input. We update the pointers accordingly. It is important to remember that both the pointers must point to the same element now.
 Finding the median is easy! It is simply the mean of the elements pointed to by the two pointers lo_median and hi_median.
 */
class MedianFinder4 {
    multiset<int> data;
    multiset<int>::iterator lo_median, hi_median;

public:
    MedianFinder4()
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
        return (*lo_median + *hi_median) * 0.5;
    }
};
