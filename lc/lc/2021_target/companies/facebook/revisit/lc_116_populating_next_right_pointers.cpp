class Solution {
public:
    Node* connect(Node* root) {
        if ( !root) return root;
                std::queue<Node*> curr;
                std::queue<Node*> next;
                curr.push(root);
                while ( !curr.empty())
                {
                        Node* node = curr.front();
                        curr.pop();
                        node->next = curr.empty() ? nullptr : curr.front();
                        if ( node->left)
                                next.push(node->left);

                        if ( node->right)
                                next.push(node->right);


                        if ( curr.empty())
                        std::swap(curr,next);
                }
                return root;
        
    }
};