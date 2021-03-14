// we will print the top view of the bt.

#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;



struct Node {
  Node *left;
  Node *right;
  int val;
};



Node *newNode(int val)
{
    Node *tmp = new Node();
    tmp->left = tmp->right = nullptr;
    tmp->val = val;
    return tmp;
}



void populate(Node *root, int x, int y, map<int, pair<int,int>> &m)
{
  if (!root) return;

  if ( !m.count(x)) {
    m[x] = make_pair(root->val, y);
  }

  else {
    if ( m[x].second > y) {
      m[x] = make_pair(root->val, y);
    }
  }

  populate(root->left, x - 1, y + 1, m);
  populate(root->right, x+1, y + 1, m);
}



vector<int> topView(Node *root) 
{
  map<int, pair<int,int>> m;
  populate(root, 0, 0, m);

  vector<int> res;
  for ( auto x : m) {
      res.push_back(x.second.first);

  }
  return res;
}



class Node {
public:
    Node *left, *right;
    int data;
    Node() { left = right = 0; }
    Node(int data)
    {
        left = right = 0;
        this->data = data;
    }
};
 
/*
          1
         / \
        2   3
         \
          4
           \
            5
             \
              6
    Top view of the above binary tree is
    2 1 3 6


    This approach is based on the level order traversal. We’ll keep record of current max so far left, right horizontal distances from the root.
And if we found less distance (or greater in magnitude) then max left so far distance then update it and also push data on this node to a stack (stack is used because in level order traversal the left nodes will appear in reverse order), or if we found greater distance then max right so far distance then update it and also push data on this node to a vector.
In this approach, no map is used.

*/
 
// class for Tree
class Tree {
public:
    Node* root;
    Tree() { root = 0; }
 
    void topView()
    {
        // queue for holding nodes and their horizontal
        // distance from the root node
        queue<pair<Node*, int> > q;
 
        // pushing root node with distance 0
        q.push(make_pair(root, 0));
 
        // hd is currect node's horizontal distance from
        // root node l is currect left min horizontal
        // distance (or max in magnitude) so far from the
        // root node r is currect right max horizontal
        // distance so far from the root node
 
        int hd = 0, l = 0, r = 0;
 
        // stack is for holding left node's data because
        // they will appear in reverse order that is why
        // using stack
        stack<int> left;
 
        // vector is for holding right node's data
        vector<int> right;
 
        Node* node;
 
        while (q.size()) {
 
            node = q.front().first;
            hd = q.front().second;
 
            if (hd < l) {
                left.push(node->data);
                l = hd;
            }
            else if (hd > r) {
                right.push_back(node->data);
                r = hd;
            }
 
            if (node->left) {
                q.push(make_pair(node->left, hd - 1));
            }
            if (node->right) {
                q.push(make_pair(node->right, hd + 1));
            }
 
            q.pop();
        }
        // printing the left node's data in reverse order
        while (left.size()) {
            cout << left.top() << " ";
            left.pop();
        }
 
        // then printing the root node's data
        cout << root->data << " ";
 
        // finally printing the right node's data
        for (auto x : right) {
            cout << x << " ";
        }
    }
};



int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right->right = newNode(6);
    cout << "Following are nodes in top view of Binary "
            "Tree\n";
    auto r = topView(root);
    for_each(begin(r), end(r), [](int x){
        cout << x << " ";
    });
    return 0;
}