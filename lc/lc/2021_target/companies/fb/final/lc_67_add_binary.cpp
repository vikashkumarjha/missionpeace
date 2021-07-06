class Solution {
public:
        string addBinary(string a, string b) {

            stack<int> stA;
            stack<int> stB;
            for ( auto c : a) stA.push(c - '0');
            for ( auto c : b) stB.push(c - '0');

            int carry = 0;
            stringstream ss;
            while ( !stA.empty() || !stB.empty())
            {
                int x = 0; int y = 0;
                if ( !stA.empty()) {
                    x = stA.top(); stA.pop();
                }
                if ( !stB.empty()) {
                    y = stB.top(); stB.pop();
                }

                int d = x + y + carry;
                if ( d == 0) {
                    ss << '0'; carry = 0; 
                }
                else if ( d == 1) {
                     ss << '1'; carry = 0; 
                }
                else if ( d == 2) {
                    ss << '0'; carry = 1;
                }
                else {
                    ss << '1'; carry = 1;
                }

            }
            if ( carry) {
                ss << '1';
            }
            string res = ss.str();
            reverse(begin(res), end(res));
            return res;


        }
};
