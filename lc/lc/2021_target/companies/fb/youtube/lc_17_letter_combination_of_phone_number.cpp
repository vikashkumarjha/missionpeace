

/*
 * Time complexity : \mathcal{O}(3^N \times 4^M)O(3
 * N
 *  ×4
 *  M
 *   ) where N is the number of digits in the input that maps to 3 letters (e.g.
 *   2, 3, 4, 5, 6, 8) and M is the number of digits in the input that maps to 4
 *   letters (e.g. 7, 9), and N+M is the total number digits in the input.
 *
 *   */
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

          std::vector<std::string> dict = { "" , "", "abc","def","ghi",
          "jkl", "mno", "pqrs","tuv","wxyz"};
        letterCombinationsHelper(digits, dict, output, result);
        return result;
    }
};
