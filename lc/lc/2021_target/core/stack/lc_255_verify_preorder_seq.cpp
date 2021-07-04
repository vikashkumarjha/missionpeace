/*
 * Given an array of unique integers preorder, return tru
 * 

 Find the first greater value on right side of current node.
   Let the index of this node be j. Return true if following
   conditions hold. Else return false
    (i)  All values after the above found greater value are
         greater than current node.
    (ii) Recursive calls for the subarrays pre[i+1..j-1] and
         pre[j+1..n-1] also return true.

         */


class Solution {
public:
    bool verify(vector<int> &a, int start, int end) {
        if ( start >= end) return true;
        int pivot = a[start];
        int idx = -1;
        // find

        for ( int i = start + 1; i <= end; i++) {
            if ( idx == -1 && a[i] > pivot) idx = i;
            if ( idx != -1 && a[i] < pivot) return false;
        }

        if ( idx == -1) {
            return verify(a, start + 1, end);
        }else {
            return verify(a, start+1, idx - 1) && verify(a, idx, end);
        }
    }

    bool verifyPreorder(vector<int>& preorder) {
        if (preorder.size() == 0) return true;
        return verify(preorder, 0, preorder.size() - 1);

    }
};

/*
 * 1) Create an empty stack.
2) Initialize root as INT_MIN.
3) Do following for every element pre[i]
     a) If pre[i] is smaller than current root, return false.
     b) Keep removing elements from stack while pre[i] is greater
        then stack top. Make the last removed item as new root (to
        be compared next).
        At this point, pre[i] is greater than the removed root
        (That is why if we see a smaller element in step a), we
        return false)
     c) push pre[i] to stack (All elements in stack are in decreasing
        order)

        */

class Solution {
public:
    bool verifyPreorder(vector<int>& pre) {
        stack<int> st;
        int n = pre.size();
        int root = INT_MIN;

        for ( int i = 0; i < n; i++) {
            if ( pre[i] < root) {
                return false;
            }

            while (!st.empty() && st.top() < pre[i]) {
                root = st.top();
                st.pop();

            }
            st.push(pre[i]);
        }
        return true;
    }
};
