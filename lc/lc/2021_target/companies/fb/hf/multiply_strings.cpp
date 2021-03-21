string multiply(string num1, string num2) {  
    int m = num1.length();
    int n = num2.length();

    vector<int> data(m+n, 0);

    for ( int i = m - 1; i >= 0; i--) {
        for (int j = n -1 ; j >= 0; j--) {
            int mul = (num1[i] - '0') * ( num2[j] - '0');
            int p1 = i + j; // carry
            int p2 = i + j + 1;
            int sum = mul + data[p2];
            data[p2] = sum % 10;
            data[p1] = pos[p1] + ( sum / 10);
        }
    }

    string result;
    for (int p : data)
        if (!(result.length() == 0 && p == 0))
            result = result + to_string(p);

    return result.length() == 0 ? "0" : result;




}
