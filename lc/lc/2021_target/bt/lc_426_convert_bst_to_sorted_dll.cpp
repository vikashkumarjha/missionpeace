// the way to do this is inorder traversal.

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
            val = _val;
            left = NULL;
            right = NULL;
        }

    Node(int _val, Node* _left, Node* _right) {
            val = _val;
            left = _left;
            right = _right;
        }
};


Node *treeToDoublyList(Node *root) {
    if ( !root) return nullptr;
    stack<Node*> st;
    Node *first = nullptr;
    Node *last = nullptr;
    while ( root || !st.empty()) {
        while (root) {
            st.push(root);
            root = root->left;
        }
        root = st.top(); st.pop();
        if ( !first) {
            first = root;
        }
        if ( last) {
            last->right  = root;
            root->left = last;
        }
        last = root;
        root = root->right;
    }
    first->left = last;
    last->right = first;
    return first;
}



Node *merge(Node *L1, Node *L2) {
    if ( !L1) return L2;
    if ( !L2) return L1;

    Node *lastL1 = L1->left;
    Node *lastL2 = L2->left;

    lastL1->right = L2;
    L2->left = lastL1;

    L1->left = lastL2;
    lastL2->right = L1;

    return L1;

}



Node *treeToDoublyList2(Node *root) {

    if (!root) return nullptr;

    Node *left = treeToDoublyList2(root->left);
    Node *right= treeToDoublyList2(root->right);

    // make the root circular
    root->left = root;
    root->right = root;

    return merge(left, merge(root, right));


}
