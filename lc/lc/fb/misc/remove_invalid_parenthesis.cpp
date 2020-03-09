//
//  remove_invalid_parenthesis.cpp
//  finishline
//
//  Created by vikash kumar jha on 2/4/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//

#if 0

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int remove_left=0, remove_right=0, pair=0;
        /*** use the unordered_set to deal with the duplicate cases ***/
        unordered_set<string> result;
        /***  calculate the remained # of left and right parentheses  ***/
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(')   remove_left++;
            else if(s[i]==')'){
                if(remove_left > 0) remove_left--;
                else    remove_right++;
            }
        }
        help(0, 0, remove_left, remove_right, s, "", result);
        /*** change the unordered_set to vector ***/
        return vector<string>(result.begin(), result.end());
    }
    
    /***
    pair : record the () pair count in the solution
    index : record the cur-position int the string s
    remove_left : the number of left parentheses needed to delete
    remove_right : the number of right parentheses needed to delete
    s : origninal input string    solution : the current produced string
    result : stores all the satisfied solution string
    ***/
    void help(int pair, int index, int remove_left, int remove_right, const string& s, string solution, unordered_set<string>& result){
        /***   end condition       ***/
        if(index==s.size()){
            /*** check whether the remained string solution is right  ***/
            if(pair==0 && remove_left==0 && remove_right==0)    result.insert(solution);
            return;
        }
        /***    left-half-parentheses     ***/
        if(s[index]=='('){
            /***    remove the left-half-parentheses     ***/
            if(remove_left > 0)     help(pair, index+1, remove_left-1, remove_right, s, solution, result);
            /***    keep  the  left-half-parentheses     ***/
            help(pair+1, index+1, remove_left, remove_right, s, solution+s[index], result);
        }
        /***    right-half-parentheses     ***/
        else if(s[index]==')'){
            /***    remove the right-half-parentheses     ***/
            if(remove_right > 0)     help(pair, index+1, remove_left, remove_right-1, s, solution, result);
            /***    keep  the  right-half-parentheses     ***/
            if(pair > 0) help(pair-1, index+1, remove_left, remove_right, s, solution+s[index], result);
        }
        /***    other-characters     ***/
        else{
            help(pair, index+1, remove_left, remove_right, s, solution+s[index], result);
        }
    }
};

#endif
