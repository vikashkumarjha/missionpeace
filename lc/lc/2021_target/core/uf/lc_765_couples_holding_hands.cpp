
/*
think this problem is variation of joint set
The approach is to create the sets based on the current (wrong) pairs, then try to do the union based on the target pairs ([0, 1],[2,3],...).
If there is a union, it means that the indexes belonged to different pairs, and we can increment the swap counter. If the union is not execute, indexes belongs to the same set that means that a previous wap already fixed them.

*/
class UF {
public:
    UF (int n) : parent(n) {}
   
    void setParent(int x, int p) {
        parent[x] = p;
    }
   
    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);
       
        return parent[x];
    }
   
    bool union_find(int x, int y) {
        int px = find(x);
        int py = find(y);
       
        if (px == py)
            return false;
       
        parent[py] = px;
        return true;
    }

// private:
    vector<int> parent;
};

//[0,2,1,3]
// make each pair (0,2) and (1,3) as there first element as parent.
// 0  1 0 1 

// now start visiting each pair and if we can do union then increase the counter



class Solution {
public:
    int minSwapsCouples(vector<int> & row) {
        if (row.empty()) return 0;

        UF uf(row.size());

        // every pair make the the firt element as parent

        for (int i = 0; i < row.size(); i += 2) {
            uf.setParent(row[i],     row[i]); // setParent(node, parent)
            uf.setParent(row[i + 1], row[i]);
        }

        for (auto x : uf.parent)
            cout << x << "\t";

        // Here we say if they belong to same subgraph, NO Sawpping is required
        //  --- Else Add extra Edge to denote connection between SubGraph and swapping
        int counter = 0;
        for (int i = 0; i < row.size(); i += 2) {
            // now do on the index 
            if (uf.union_find(i, i + 1))
                counter++;
        }

        return counter;
    }
};
