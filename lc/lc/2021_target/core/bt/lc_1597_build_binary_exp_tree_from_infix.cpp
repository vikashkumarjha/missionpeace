A binary expression tree is a kind of binary tree used to represent arithmetic expressions. Each node of a binary expression tree has either zero or two children. Leaf nodes (nodes with 0 children) correspond to operands (numbers), and internal nodes (nodes with 2 children) correspond to the operators '+' (addition), '-' (subtraction), '*' (multiplication), and '/' (division).

For each internal node with operator o, the infix expression that it represents is (A o B), where A is the expression the left subtree represents and B is the expression the right subtree represents.

You are given a string s, an infix expression containing operands, the operators described above, and parentheses '(' and ')'.

Return any valid binary expression tree, which its in-order traversal reproduces s after omitting the parenthesis from it (see examples below).

Please note that order of operations applies in s. That is, expressions in parentheses are evaluated first, and multiplication and division happen before addition and subtraction.

Operands must also appear in the same order in both s and the in-order traversal of the tree.


Input: s = "3*4-2*5"
Output: [-,*,*,3,4,2,5]
Explanation: The tree above is the only valid tree whose inorder traversal produces s.


/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int prec(char ch){
        if(ch == '+' || ch == '-')
            return 1;
        else if(ch == '*' || ch == '/')
            return 2;
        return -1;
    }

    string postFix(string & s){
        string str = "";
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i] >= '0' && s[i] <= '9')
                str+=s[i];
            else if(s[i] == '(')
                st.push(s[i]);
            else if(s[i] == ')'){
                while(!st.empty() && st.top() != '('){
                    str+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                while(!st.empty() && prec(s[i]) <= prec(st.top())){
                    str+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            str+=st.top();
            st.pop();
        }
        return str;
    }

    Node* helper(string & s){
        stack<Node*> st;
        for(int i=0;i<s.length();i++){
            if(s[i] >= '0' && s[i] <= '9'){
                Node* n = new Node(s[i] );
                st.push(n);
            }
            else{
                Node* n1 = st.top();
                st.pop();
                Node* n2 = st.top();
                st.pop();
                Node* n = new Node(s[i]);
                n->right = n1;
                n->left = n2;
                st.push(n);
            }
        }
        return st.top();
    }

    Node* expTree(string s) {
        string str = postFix(s);
        //return NULL;
        return helper(str);
    }
};
