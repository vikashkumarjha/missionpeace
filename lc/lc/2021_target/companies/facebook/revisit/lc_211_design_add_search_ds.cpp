class TrieNode{
public:
        TrieNode() : isLeaf(false){
            for ( int i = 0; i < 26; i++){
                children[i] = nullptr;
            }
        }
        void insert(std::string& s);
        bool search(const std::string s, TrieNode* curr);
       
private:
       
        bool isLeaf;
        TrieNode* children[26];


};


void TrieNode::insert(std::string& s){
    TrieNode* root = this;
    for ( int i = 0; i < s.length(); i++)
    {
        int index = s[i] - 'a';
        if ( root->children[index] == nullptr){
            root->children[index] = new TrieNode();
        }
        root = root->children[index];
    }
    root->isLeaf = true;

}

bool TrieNode::search(const std::string s, TrieNode* root){

    for ( int i = 0; root && i < s.length(); i++){
        int index = s[i] - 'a';
        //case when .
        if ( s[i] == '.'){
            bool ret = false;
            for ( int j = 0; j < 26;j++){
                if ( root->children[j])
                    ret |= search(s.substr(i+1), root->children[j]);    
            }
            return ret;
            
        }else if (root->children[index]){
            root = root->children[index];
        }else{
            return false;
        }
    }
    return (root && root->isLeaf );
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
