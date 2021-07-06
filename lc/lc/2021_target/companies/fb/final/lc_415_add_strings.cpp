class Solution {
public:
    string addStrings(string num1, string num2) {
        stack<int> st1;
        stack<int> st2;
        stringstream ss;
        for ( auto c : num1) {
            st1.push(c);
        }

        for ( auto c : num2) {
            st2.push(c);
        }

        int carry = 0;
        while (!st1.empty() || !st2.empty()) {
            int x = 0;
            int y = 0;
            if (!st1.empty()) {
                x = st1.top() - '0'; st1.pop();
            }

            if (!st2.empty()) {
                y = st2.top() - '0'; st2.pop();
            }

            int d = ( x + y + carry) % 10;
            carry = ( x + y + carry) / 10;
            ss << to_string(d);

        }

        if ( carry) {
            ss << "1";
        }

        string res = ss.str();
        reverse(begin(res), end(res));
        return res;

    }
};
