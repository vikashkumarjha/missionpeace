class Solution {
public:
    
    void letterCombinationsHelper(std::string& digits , std::vector<std::string> &dict , std::string& current,           std::vector<std::string>& result)
{
  if ( current.length() == digits.length())
  {
    if ( !current.empty())  
        result.push_back(current);
    return;
  }

  int dictIndex = digits[current.length()] - '0';
  for ( int i = 0; i < dict[dictIndex].length(); ++i)
  {
    current.push_back(dict[dictIndex][i]);
    letterCombinationsHelper(digits,dict,current,result);
    current.pop_back();
  }

}
    
    vector<string> letterCombinations(string digits) {
        
        std::string output;
        std::vector<std::string> result;
        std::vector<std::string> dict = { "" , "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        letterCombinationsHelper(digits, dict, output, result);
        return result;
        
    }
};