class Solution {
public:
    Node* connect(Node* root) {
        Node *prev = NULL;
        if(root == NULL) return root;
        if(root != NULL) root->next = prev;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            Node *x;
            for(int i=0;i<n;i++) {
                x = q.front();
                q.pop();
                if(prev != NULL) {
                    prev->next = x;
                }
                prev = x;
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
            x->next = NULL;
            prev = NULL;
        }

        return root;
    }
};
