class Solution {
public:
    void wiggleSort(vector<int> & arr) {        
        int n = arr.size();
        if (n < 2) return;

        // Here we taek care of i - 1  and i + 1 when we are at ith Index.
        // -- we need to form :  /\ at distance of 2 indexs
       
        for (int i = 1; i < n; i = i + 2) {
            if (arr[i - 1] >  arr[i])
                swap(arr[i - 1],  arr[i]);

            // We perform this Operation, if we are allowed to do so
            if (i + 1 < n && arr[i + 1] > arr[i])
                 swap(arr[i + 1],  arr[i]);
        }
    }
};


class Solution {
public:
    void wiggleSort(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        
        int N =nums.size();
        for (int i = 1; i < N - 1; i = i + 2){
            swap(nums[i], nums[i+1]);
        }
       
    }
    
};