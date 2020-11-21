class Solution {
public:
    bool judgeCircle(string moves) {
        std::pair<int,int> curr_pos;
        int n = moves.length();
        for ( int i = 0; i < n; i++)
        {
            char c = moves[i];
            int dist = std::abs( curr_pos.first) + std::abs(curr_pos.second);
            int remaining_moves = n - i;
            if ( dist > remaining_moves) return false;
            switch(c)
            {
                case 'U':
                    curr_pos.second++;
                    break;

                case 'D':
                    curr_pos.second--;
                    break;

                case 'L':
                    curr_pos.first--;
                    break;

                case 'R':
                    curr_pos.first++;
                    break;
            }

        }
        return ( curr_pos.first == 0 && curr_pos.second == 0);

    }
};
