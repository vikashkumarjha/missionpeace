/*
Given an array of strings words representing an English Dictionary, return the longest word in words that can be built one character at a time by other words in words.

If there is more than one possible answer, return the longest word with the smallest lexicographical order. If there is no answer, return the empty string.

 

Example 1:

Input: words = ["w","wo","wor","worl","world"]
Output: "world"
Explanation: The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".

*/

class TrieNode{
	public:
		TrieNode() {
		isLeaf = false;
		for (int i = 0; i < 26;i++)
			children[i] = nullptr;
		}
		void insert(std::string& key);
		//bool search(const std::string& key);
		void get_longest_word(TrieNode* curr, std::string& p, std::string& result);
		
	private:
		bool isLeaf;
		TrieNode* children[26];
		
		

};


void TrieNode::insert(std::string& key)
{
	TrieNode* curr = this;

	for ( int i=0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if ( curr->children[index] == nullptr) {
			curr->children[index] = new TrieNode();
		}
		curr = curr->children[index];
	}
	curr->isLeaf = true;
}
/*
bool TrieNode::search(const std::string& key)
{
	TrieNode* curr = this;

	for ( int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if ( curr->children[index] == nullptr)
			return false;

		curr = curr->children[index];
	}
	return ( curr && curr->isLeaf );
}
*/

void TrieNode::get_longest_word(TrieNode* curr, std::string &prefix,std::string& result)
{
    if ( curr->isLeaf){
        if ( prefix.length() > result.length()){
            result = prefix;
        }
    }
    for ( int i=0 ;  i < 26; i++){
        if ( curr->children[i] && curr->children[i]->isLeaf ){
            prefix.push_back('a' + i);
            get_longest_word(curr->children[i], prefix,result);
            prefix.pop_back();
        }
    }

}



class Solution {
public:
    string longestWord(vector<string>& words) {
        TrieNode *root = new TrieNode();
        for ( int i = 0; i < words.size();i++) 
            root->insert(words[i]);
    
    std::string result;
    std::string prefix;
    root->get_longest_word(root,prefix,result);
    return result;
        
    }
};