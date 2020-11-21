 string addStrings(string num1, string num2) {
     int n1 = num1.length();
     int n2 = num2.length();

     string result;
     std::reverse(num1.begin(), num1.end());
     std::reverse(num2.begin(), num2.end());
     int carry = 0;

     for ( int i = 0, j = 0; i < n1 || j < n2; ++i, ++j) {
         int a = ( i < n1) ? num1[i] - '0' ? 0;
         int b = ( j < n2) ? num2[j] - '0' ? 0;
         int sum = a + b + carry;
         result += to_string(sum % 10);
         carry = sum / 10;
     }
     if ( carry) 
         result += "1";

     std::reverse(result.begin(), result.end());
     return result;

 }
