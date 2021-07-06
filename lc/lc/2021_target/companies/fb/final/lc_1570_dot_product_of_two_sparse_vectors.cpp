class SparseVector {
public:

    SparseVector(vector<int> &nums) {
        for ( int i = 0; i < nums.size(); i++)
        {
            if ( nums[i] != 0) {
                data[i] = nums[i];        
            }
        }
        size = nums.size();


    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int res = 0;
        for ( int i = 0; i < vec.getSize(); i++) {
            if ( data.count(i) && vec.getVal(i) != 0) {
                res += (data[i] * vec.getVal(i));
            }       
        }
        return res;

    }

    int getSize() {
        return size;
    }

    int getVal(int i) {
        if ( data.count(i)) {
            return data[i];
        }
        return 0;
    }


private:
    unordered_map<int,int> data;
    int size;
};

