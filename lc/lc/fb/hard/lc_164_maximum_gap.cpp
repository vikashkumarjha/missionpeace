/*
 * Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Return 0 if the array contains less than 2 elements.

Example 1:

Input: [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either
             (3,6) or (6,9) has the maximum difference 3.

*/




class Solution {
public:
    int maximumGap(vector<int>& nums)
    {
        if (nums.empty() || nums.size() < 2)            // check if array is empty or small sized
            return 0;

        sort(nums.begin(), nums.end());                 // sort the array

        int maxGap = 0;

        for (int i = 0; i < nums.size() - 1; i++)
            maxGap = max(nums[i + 1] - nums[i], maxGap);

        return maxGap;
    }
};






/*
 *
 * Time complexity: O(n + b) \approx O(n)O(n+b)≈O(n).

Distributing the elements of the array takes one linear pass (i.e. O(n)O(n) complexity). Finding the maximum gap among the buckets takes a linear pass over the bucket storage (i.e. O(b)O(b) complexity). Hence overall process takes linear runtime.

orting an entire array can be costly. At worst, it requires comparing each element with every other element. What if we didn't need to compare all pairs of elements? That would be possible if we could somehow divide the elements into representative groups, or rather, buckets. Then we would only need to compare these buckets.

Digression: The Pigeonhole Principle The Pigeonhole Principle states that if nn items are put into mm containers, with n > mn>m, then at least one container must contain more than one item.

Suppose for each of the nn elements in our array, there was a bucket. Then each element would occupy one bucket. Now what if we reduced, the number of buckets? Some buckets would have to accommodate more than one element.

Now let's talk about the gaps between the elements. Let's take the best case, where all elements of the array are sorted and have a uniform gap between them. This means every adjacent pair of elements differ by the same constant value. So for nn elements of the array, there are n-1n−1 gaps, each of width, say, tt. It is trivial to deduce that t = (max - min)/(n-1)t=(max−min)/(n−1) (where maxmax and minmin are the minimum and maximum elements of the array). This width is the maximal width/gap between two adjacent elements in the array; precisely the quantity we are looking for!

One can safely argue that this value of tt, is in fact, the smallest value that tt can ever accomplish of any array with the same number of elements (i.e. nn) and the same range (i.e. (max - min)(max−min)). To test this fact, you can start with a uniform width array (as described above) and try to reduce the gap between any two adjacent elements. If you reduce the gap between arr[i-1]arr[i−1] and arr[i]arr[i] to some value t - pt−p, then you will notice that the gap between arr[i]arr[i] and arr[i+1]arr[i+1] would have increased to t + pt+p. Hence the maximum attainable gap would have become t + pt+p from tt. Thus the value of the maximum gap tt can only increase.

Buckets!

Coming back to our problem, we have already established by application of the Pigeonhole Principle, that if we used buckets instead of individual elements as our base for comparison, the number of comparisons would reduce if we could accommodate more than one element in a single bucket. That does not immediately solve the problem though. What if we had to compare elements within a bucket? We would end up no better.

So the current motivation remains: somehow, if we only had to compare among the buckets, and not the elements within the buckets, we would be good. It would also solve our sorting problem: we would just distribute the elements to the right buckets. Since the buckets can be already ordered, and we only compare among buckets, we wouldn't have to compare all elements to sort them!

But if we only had buckets to compare, we would have to ensure, that the gap between the buckets itself represent the maximal gap in the input array. How do we go about doing that?

We could do that just by setting the buckets to be smaller than t = (max - min)/(n-1)t=(max−min)/(n−1) (as described above). Since the gaps (between elements) within the same bucket would only be \leq t≤t, we could deduce that the maximal gap would indeed occur only between two adjacent buckets.

Hence by setting bucket size bb to be 1 < b \leq (max - min)/(n-1)1<b≤(max−min)/(n−1), we can ensure that at least one of the gaps between adjacent buckets would serve as the maximal gap.

Clarifications

A few clarifications are in order:

Would the buckets be of uniform size? Yes. Each of them would be of the same size bb.

But, then wouldn't the gap between them be uniform/constant as well? Yes it would be. The gap between them would be 11 integer unit wide. That means a two adjacent buckets of size 33 could hold integers with values, say, 3 - 63−6 and 7 - 97−9. We avoid overlapping buckets.

Then what are you talking about when you say the gap between two adjacent buckets could be the maximal gap? When we are talking about the size of a bucket, we are talking about its holding capacity. That is the range of values the bucket can represent (or hold). However the actual extent of the bucket are determined by the values of the maximum and minimum element a bucket holds. For example a bucket of size 55 could have a capacity to hold values between 6 - 106−10. However, if it only holds the elements 7, 87,8 and 99, then its actual extent is only (9 - 7) + 1 = 3(9−7)+1=3 which is not the same as the capacity of the bucket.

Then how do you compare adjacent buckets? We do that by comparing their extents. Thus we compare the minimum element of the next bucket to the maximum element of the current bucket. For example: if we have two buckets of size 55 each, holding elements [1, 2, 3][1,2,3] and [9, 10][9,10] respectively, then the gap between the buckets would essentially refer to the value 9 - 3 = 69−3=6 (which is larger than the size of either bucket).

But then aren't we comparing elements again?! We are, yes! But only compare about twice the elements as the number of buckets (i.e. the minimum and maximum elements of each bucket). If you followed the above, you would realize that this amount is certainly less than the actual number of elements in the array, given a suitable bucket size was chosen.

*/



class Bucket {
public:
    bool used = false;
    int minval = numeric_limits<int>::max();        // same as INT_MAX
    int maxval = numeric_limits<int>::min();        // same as INT_MIN
};

int maximumGap(vector<int>& nums)
{
    if (nums.empty() || nums.size() < 2)
        return 0;

    int mini = *min_element(nums.begin(), nums.end()),
        maxi = *max_element(nums.begin(), nums.end());

    int bucketSize = max(1, (maxi - mini) / ((int)nums.size() - 1));        // bucket size or capacity
    int bucketNum = (maxi - mini) / bucketSize + 1;                         // number of buckets
    vector<Bucket> buckets(bucketNum);

    for (auto&& num : nums) {
        int bucketIdx = (num - mini) / bucketSize;                          // locating correct bucket
        buckets[bucketIdx].used = true;
        buckets[bucketIdx].minval = min(num, buckets[bucketIdx].minval);
        buckets[bucketIdx].maxval = max(num, buckets[bucketIdx].maxval);
    }

    int prevBucketMax = mini, maxGap = 0;
    for (auto&& bucket : buckets) {
        if (!bucket.used)
            continue;

        maxGap = max(maxGap, bucket.minval - prevBucketMax);
        prevBucketMax = bucket.maxval;
    }

    return maxGap;
}




