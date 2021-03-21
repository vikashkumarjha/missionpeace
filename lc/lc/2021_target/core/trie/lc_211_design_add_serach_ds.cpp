/*
Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.


*/

#include "../header.hpp"


class TrieNode {
    public:
    TrieNode()  {
        for ( int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isLeaf = false;
    }
    void insert(string w);
    bool search(string w, TrieNode *root);

    private:
    TrieNode *children[26];
    bool isLeaf;


};

void TrieNode::insert(string w) {
    TrieNode *root = this;
    for ( auto ch : w) {
        int idx = ch - 'a';
        if ( root->children[idx] == nullptr) {
            root->children[idx] = new TrieNode();
        }
        root = root->children[idx];
    }

    root->isLeaf = true;
}

bool TrieNode::search(string w, TrieNode *root) {

    for ( int i = 0; i < w.size(); i++) {
        if ( w[i] == '.') {
            bool ret = false;
            for ( int j = 0; j < 26; j++) {
                if ( root->children[i]) {
                    ret |= search(w.substr(i+1), root->children[i]);
                }
            }
            return ret;
        }else if ( root->children[i]) {
            root = root->children[i];
        }else {
            return false;
        }
    }

    return ( root && root->isLeaf);
}





class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        root->insert(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return root->search(word,root);
    }
    private:
        TrieNode* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */