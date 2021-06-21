class Solution {
public:
  
        
    
void generateParenthesisHelper(int max, std::string curr, int left, int right, std::vector<string> &result){

    if ( curr.length() == 2 * max){
        result.push_back(curr);
        return;
    }
    if ( left < max){
        generateParenthesisHelper(max, curr + "(" , left + 1, right, result);
    }
    if ( right < left){
        generateParenthesisHelper(max, curr + ")" , left , right + 1, result);

    }
}

vector<string> generateParenthesis(int n) {
    std::vector<string> result;
    std::string curr;
    generateParenthesisHelper(n, curr, 0, 0, result);
    return result;

}
};