/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    void dfs(Node *root, unordered_map<Node*,NodeCopy*> &m) {
        if (!root) return;
        
        m[root] = new NodeCopy(root->val);
        
        dfs(root->left, m);
        dfs(root->right, m);
      
    }
    
    
    NodeCopy* copyRandomBinaryTree(Node* root) {
        
        unordered_map<Node*,NodeCopy*> m;
        dfs(root, m);
        
        for ( auto it : m) {
            if (it.first) {
                it.second->left =  m[it.first->left];
                it.second->right = m[it.first->right];
                it.second->random = m[it.first->random];
            }
           
        }
        
        return m[root];
        
    }
};


This can be solved with a simple DFS with a HashMap.
First we check if the node is null, if not, we check if it's in our map, if not - we create a copy of our current node and run DFS again on the left, right and random nodes.

One edge case to notice is that if there's a cycle in the tree (a random pointer looking at previous visited node) then the map would never be filled.
To solve this we need to create the CopyNode, and immediately put it in the map.
That way, when there's a cycle - we'd just return the node we put in the map and end the infinite loop.



 NodeCopy* help(Node* root){
        if(root==NULL) return NULL;
        if(mmap.count(root)==1)return mmap[root];

        NodeCopy* newroot=new NodeCopy(root->val);
        mmap[root]=newroot;

        newroot->left=help(root->left);
        newroot->right=help(root->right);
        newroot->random=help(root->random);

        return newroot;

    }
    NodeCopy* copyRandomBinaryTree(Node* root) {
        return help(root);
    }
    unordered_map<Node*, NodeCopy*> mmap;

