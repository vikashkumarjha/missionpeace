class Solution {
public:
    int myAtoi(string s) {
        
        int i = 0;
  int n = s.length();
  long result = 0;
  int sign = 1;
  for ( ; i < n ;)
  {
    while ( std::isspace(s[i]) ) i++;
    if ( s[i] == '+' || s[i] == '-')
    {
      sign = ( s[i] == '+') ? 1 : -1;
      ++i;
    }

    while ( i < n && std::isdigit(s[i]))
    {
      result = result * 10 + (s[i++] - '0');
      if ( result * sign >= INT_MAX )return INT_MAX;
      if ( result * sign <= INT_MIN ) return INT_MIN;
    }

    return ( result * sign);
  }
  return  result * sign;
        
    }
};