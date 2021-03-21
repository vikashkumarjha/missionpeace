/*
Given a list of strings words representing an English Dictionary, find the longest word in words that can be built one character at a time by other words in words. If there is more than one possible answer, return the longest word with the smallest lexicographical order.

If there is no answer, return the empty string.
Example 1:
Input: 
words = ["w","wo","wor","worl", "world"]
Output: "world"
Explanation: 
The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
Example 2:
Input: 
words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
Output: "apple"
Explanation: 
Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".

*/


class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> built;
        string res;
        for (string w : words) {
            if (w.size() == 1 || built.count(w.substr(0, w.size() - 1))) {
                res = w.size() > res.size() ? w : res;
                built.insert(w);
            }
        }
        return res;
    }
};



class TrieNode{
	public:
		TrieNode() {
		isLeaf = false;
		for (int i = 0; i < 26;i++)
			children[i] = nullptr;
		}
		void insert(std::string& key);
		bool search(const std::string& key);
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