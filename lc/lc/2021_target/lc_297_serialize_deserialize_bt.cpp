#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <list>
#include <memory>
#include <cstdlib>
#include <sstream>

using namespace std;

struct TreeNode {
	TreeNode (int x) : val(x) , left(nullptr) , right(nullptr) {}
	int val;
	TreeNode *left;
	TreeNode *right;
};



class Codec {
private:
	void serialize_helper(TreeNode* root, ostringstream &ss) {
		if ( root ) {
			// note
			ss << root->val << ' ';
			serialize_helper(root->left, ss);
			serialize_helper(root->right, ss);
		}else {
			// note
			ss << "# ";
		}
	}
	TreeNode* deserialize_helper(istringstream &iss) {
		string v;
		iss >> v;
		if ( v == "#") return nullptr;

		TreeNode *root = new TreeNode(stoi(v));
		root->left = deserialize_helper(iss);
		root->right = deserialize_helper(iss);
		return root;

	}

public:
	string serialize(TreeNode *root) {
	    if ( !root ) return "";
	    ostringstream ss;
	    serialize_helper(root, ss);
	    return ss.str();

	}
	TreeNode* deserialize(string &s){
		if ( s.empty() ) return nullptr;
		istringstream iss(s);
		return deserialize_helper(iss);
	}


};

void inorder(TreeNode *root) {
	if ( !root) return;
	std::cout << root->val << " ";
	inorder(root->left);
	inorder(root->right);
}



int main() 
{
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(5);

	Codec codec;
	string output = codec.serialize(root);
	std::cout << "\n The value of the serialization output: " << output;
	TreeNode *recovered = codec.deserialize(output);
	inorder(recovered);
	return 0;

}














