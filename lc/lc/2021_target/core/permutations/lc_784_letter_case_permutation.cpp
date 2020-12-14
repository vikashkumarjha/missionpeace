/*
Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. You can return the output in any order.

 

Example 1:

Input: S = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]
Example 2:

Input: S = "3z4"
Output: ["3z4","3Z4"]
Example 3:

Input: S = "12345"
Output: ["12345"]

*/

class Solution {
public:
	vector<string> ans;
	void dfs(string& S, int index, string path){
		if(index==S.size()){
			ans.push_back(path);
			return;
		}
		if(isalpha(S[index])){
			char temp1=toupper(S[index]);
			char temp2=tolower(S[index]);
			dfs(S,index+1,path+temp1);
			dfs(S,index+1,path+temp2); 
		}
		else{
			dfs(S,index+1,path+S[index]);
		}
	}
	vector<string> letterCasePermutation(string S) {
		if(S.size()==0) return ans;
		string path="";
		dfs(S,0,path);
		return ans; 
	}
};