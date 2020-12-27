/*
Design a data structure that is initialized with a list of different words. Provided a string, you should determine if you can change exactly one character in this string to match any word in the data structure.

Implement the MagicDictionary class:

MagicDictionary() Initializes the object.
void buildDict(String[] dictionary) Sets the data structure with an array of distinct strings dictionary.
bool search(String searchWord) Returns true if you can change exactly one character in searchWord to match any string in the data structure, otherwise returns false.
 

Example 1:

Input
["MagicDictionary", "buildDict", "search", "search", "search", "search"]
[[], [["hello", "leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]
Output
[null, null, false, true, false, false]

Explanation
MagicDictionary magicDictionary = new MagicDictionary();
magicDictionary.buildDict(["hello", "leetcode"]);
magicDictionary.search("hello"); // return False
magicDictionary.search("hhllo"); // We can change the second 'h' to 'e' to match "hello" so we return True
magicDictionary.search("hell"); // return False
magicDictionary.search("leetcoded"); // return False

*/

// typical trie implementation 
struct Node {
    array<Node*, 26> next; // faster than vector, Node *[26] also works but then u need to memset/bzero
    bool isWord;
    Node() {
        next.fill(nullptr);
        isWord = false;
    }
}; 

class Trie {
public:
    Node *root;
    Trie() : root(new Node()) {}
    void insert(string s) {
        Node *cur = root;
        for (char c : s) {
            if (!cur->next[c - 'a']) 
                cur->next[c - 'a'] = new Node();
            cur = cur->next[c - 'a'];
        }
        cur->isWord = true;
    }
    bool find(string s, Node* p = nullptr) {
        if (!p) p = root;
        for (char c : s) {
            if (p->next[c - 'a']) p = p->next[c - 'a'];
            else return false ;
        }
        return p->isWord;
    }
	// the reason why I put the implementation here is to have access to the root trieNode
	// which is typically hidden by the trie implementation 
    bool search(string s) {
        Node *p = root;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            for (int j = 0; j < 26; j++) {
				 // skip when we found a node that's the same as the current character
                if (c == (char)(j + 'a')) continue;
				// if we skip this node and have the rest of the characters matched, we found the answer
				// we dont need to care about 0..i - 1, because it's guarentee to be matched (p = p-next[c - 'a'])
				// i + 1, becuase we "modified" i
                if (p->next[j] && find(s.substr(i + 1), p->next[j])) return true;
            }
            p = p->next[c - 'a'];
            if (!p) return false ;
        }
        return false;
    }
};


class MagicDictionary {
public:
    Trie *t;
    MagicDictionary() {
        t = new Trie();
    }
    
    void buildDict(vector<string> dictionary) {
        for (string s : dictionary) 
            t->insert(s);
    }
    
    bool search(string searchWord) {
        return t->search(searchWord);
    }
};
};