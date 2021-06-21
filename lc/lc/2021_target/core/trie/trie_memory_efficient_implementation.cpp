#include <unordered_map>
#include <iostream>

using namespace std;


struct TrieNode {
    bool isLeaf;
    unordered_map<char,TrieNode*> children; 

};

TrieNode *getNewTrieNode() {
    TrieNode *n = new TrieNode;
    n->isLeaf = false;
    return n;
}

void insert(TrieNode*& head, string s) {
    if ( head == nullptr) {
        head = getNewTrieNode();
    }

    TrieNode *curr = head;

    for ( int i = 0; i < s.length(); i++) {
        if ( !curr->children.count(s[i])) {
                curr->children[s[i]] = getNewTrieNode();
        }
        curr = curr->children[s[i]];
    }

    curr->isLeaf = true;

}


bool haveChildren(TrieNode const *curr) {
    for ( auto it : curr->children) {
        if ( it.second ) {
            return true;
        }
    }
    return false;

}
// Recursive function to delete a string from a Trie
bool deletion(TrieNode*& curr, char* str)
{
    // return if Trie is empty
    if (curr == nullptr) {
        return false;
    }
 
    // if the end of the string is not reached
    if (*str)
    {
        // recur for the node corresponding to the next character in
        // the string and if it returns true, delete the current node
        // (if it is non-leaf)
        if (curr != nullptr && curr->children.find(*str) != curr->children.end() &&
            deletion(curr->children[*str], str + 1) && curr->isLeaf == false)
        {
            if (!haveChildren(curr))
            {
                delete curr;
                curr = nullptr;
                return true;
            }
            else {
                return false;
            }
        }
    }
 
    // if the end of the string is reached
    if (*str == '\0' && curr->isLeaf)
    {
        // if the current node is a leaf node and doesn't have any children
        if (!haveChildren(curr))
        {
            delete curr;    // delete the current node
            curr = nullptr;
            return true;    // delete the non-leaf parent nodes
        }
 
        // if the current node is a leaf node and has children
        else {
            // mark the current node as a non-leaf node (DON'T DELETE IT)
            curr->isLeaf = false;
            return false;   // don't delete its parent nodes
        }
    }
 
    return false;
}
 
// Iterative function to search a string in a Trie. It returns true
// if the string is found in the Trie; otherwise, it returns false.
bool search(TrieNode* head, char* str)
{
    // return false if Trie is empty
    if (head == nullptr) {
        return false;
    }
 
    TrieNode* curr = head;
    while (*str)
    {
        // go to the next node
        curr = curr->children[*str];
 
        // if the string is invalid (reached end of a path in the Trie)
        if (curr == nullptr) {
            return false;
        }
 
        // move to the next character
        str++;
    }
 
    // return true if the current node is a leaf and the
    // end of the string is reached
    return curr->isLeaf;
}

// Memory efficient Trie implementation in C++ using Map
int main()
{
    TrieNode* head = nullptr;
 
    insert(head, "hello");
    cout << search(head, "hello") << " ";       // print 1
 
    insert(head, "helloworld");
    cout << search(head, "helloworld") << " ";  // print 1
 
    cout << search(head, "helll") << " ";       // print 0 (Not present)
 
    insert(head, "hell");
    cout << search(head, "hell") << " ";        // print 1
 
    insert(head, "h");
    cout << search(head, "h") << endl;          // print 1 + newline
 
    deletion(head, "hello");
    cout << search(head, "hello") << " ";       // print 0 (`hello` deleted)
    cout << search(head, "helloworld") << " ";  // print 1
    cout << search(head, "hell") << endl;       // print 1 + newline
 
    deletion(head, "h");
    cout << search(head, "h") << " ";           // print 0 (`h` deleted)
    cout << search(head, "hell") << " ";        // print 1
    cout << search(head, "helloworld") << endl; // print 1 + newline
 
    deletion(head, "helloworld");
    cout << search(head, "helloworld") << " ";  // print 0
    cout << search(head, "hell") << " ";        // print 1
 
    deletion(head, "hell");
    cout << search(head, "hell") << endl;       // print 0 + newline
 
    if (head == nullptr) {
        cout << "Trie empty!!\n";               // Trie is empty now
    }
 
    cout << search(head, "hell");               // print 0
 
    return 0;
}





