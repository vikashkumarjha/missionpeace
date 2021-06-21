class Solution {
public:
    int helper(unordered_map<int,bool>&m,int val)
    {
        if(!m.count(val)) return 0;
        if(m[val]) return 0;
        m[val]=true;
        int ans=1;
        ans+=helper(m,val+1);
        ans+=helper(m,val-1);
        return ans;
    }
    int longestConsecutive(vector<int>& A) {
        unordered_map<int ,bool> m;
        for(int i=0;i<A.size();++i)
            m[A[i]]=false;
        int maxv=0;
        for(int i=0;i<A.size();++i)
            maxv = max(maxv,helper(m,A[i]));
        return maxv;
    }
};


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if ( nums.size() == 0 ) return 0;
        unordered_set<int> _myset(nums.begin(),nums.end());
    int ans = 1;

    for ( int i = 0; i < nums.size(); i++)
    {
        if ( _myset.find(nums[i] - 1) != _myset.end())
        {
            int j = nums[i];
            while ( _myset.find(j) != _myset.end())
            {
                j++;
            }
            ans = std::max(ans,j- nums[i] + 1);
        }
    }
    return ans;

    }
};
