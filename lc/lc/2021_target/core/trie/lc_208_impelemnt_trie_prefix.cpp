/*
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true

*/

#include "../header.hpp"


struct TrieNode{
    TrieNode() : isLeaf(false) {
        for ( int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
    }
    bool isLeaf;
    TrieNode* children[26];
};


class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = root;
        for ( int i = 0; i < word.length(); i++){
            int index = word[i] - 'a';
            if ( curr->children[index] == nullptr){
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isLeaf = true;
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curr = root;
        for ( int i = 0; i < word.size(); i++){
            int index = word[i] - 'a';
            if ( curr->children[index] == nullptr){
                return false;
            }
            curr = curr->children[index];
        }
        return ( curr && curr->isLeaf);
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for ( int i = 0; i < prefix.length(); i++){
            int index = prefix[i] - 'a';
            if ( curr->children[index] == nullptr)
                return false;
            curr = curr->children[index];
        }
        // here we have the prefix 
        return true;
        
    }
    private:
        TrieNode* root;

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */