
// ONE complement flip bit.
class Solution {
public:
    int findComplement(int num) {

        int res = num;
        int i = 0;

        while(num)
        {
            res ^= (1<<i);
            num /= 2;
            i++;
        }

        return res;
    }
};
