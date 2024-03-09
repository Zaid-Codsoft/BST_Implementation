#include<iostream>
using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node(int v):val(v),left(NULL),right(NULL){}
};
class BST {
	Node* root;
	
	bool isEmpty(Node* root) {
		if (root == NULL) {
			return true;
		}
		else return false;
	}

	Node* insert(Node* root, int d) {

		Node* newnode = new Node(d);
		if (root==nullptr) {
			return newnode;
			
		}
		if (d < root->val) {
			root->left = insert(root->left, d);
		}
		else if (d > root->val) {
			root->right= insert(root->right, d);
		}
		return root;
	}
	Node* findmin(Node* node) {
		while (node->left != nullptr) {
			node = node->left;
		}
		return node;
	}
	Node* deleteing(Node* root, int v) {
		if (root == nullptr) {
			return nullptr;
		}
		if (v < root->val) {
			root->left=deleteing(root->left, v);
		}
		else if (v > root->val) {
			root->right=deleteing(root->right, v);
		}
		else {
			if (root->left == nullptr) {
				Node* temp = root->right;
				delete root;
				return temp;
			}
			else if (root->right == nullptr) {
				Node* temp = root->left;
				delete root;
				return temp;
			}
			else {
				Node* Temp = findmin(root->right);
				root->val = Temp->val;
				root->right = deleteing(root->right, Temp->val);
			}

		}
		return root;
	}
	void displayroot(Node* root) {
		if (root != nullptr) {
			displayroot(root->left);
			cout << root->val << " ";
			displayroot(root->right);
		}
	}
	Node* findparent(Node* root, int v) {
		if (root == nullptr || (root->left && root->left->val == v) || (root->right && root->right->val == v)) {
			
			return root;
		}

		if (v < root->val) {
			return findparent(root->left, v);
		}
		else {
			return findparent(root->right, v);
		}
	}
	Node* findchildern(Node* root,int v) {
		if (root->val==v) {
			if (root->left == nullptr&&root->right!= nullptr) {
				cout << "only right child : " << root->right->val<<" \n";
				return root;
			}
			else if (root->right == nullptr && root->left != nullptr) {
				cout << "only left child : " << root->left->val << " \n";
				return root;
			}
			else if (root->left != nullptr && root->right != nullptr) {
				cout << " \nTwo child exist : \n";
				cout << " \n1.  left :" << root->left->val;
				cout << " \n2.  right :" << root->right->val;
				return root;
			}
			else {
				cout << "\n NO child exist :\n";
				return root;
			}
		}
		else if (v < root->val) {
			root->left = findchildern(root->left, v);
		}
		else if (v > root->val) {
			root->right = findchildern(root->right, v);
		}
		return root;
	}
public:
	BST() : root(NULL) {}
	void ins(int d) {
		root=insert(root, d);
		}
	void display() {
		displayroot(root);
	}
	void delet(int d) {
		root = deleteing(root, d);
	}
	void parent(int d) {
		Node* finding=findparent(root, d);
		cout << "\n Parent : " << finding->val<<"\n";
	}
	void childerm(int v) {
		root = findchildern(root, v);
	}

};

int main() {
	BST b;
	b.ins(33);
	b.ins(41);
	b.ins(23);
	b.ins(43);
	b.ins(42);
	b.ins(24);
	b.ins(21);
	b.display();
	//b.delet(23);
	cout << "\n --- \n";
	b.display();
	cout << "\n --- \n";
	b.parent(21);
	cout << "\n --- \n";
	b.parent(41);
	cout << "\n --- \n";
	b.parent(42);
	cout << "\n --- \n";
	b.childerm(33);
	cout << "\n --- \n";
	b.childerm(43);
	cout << "\n --- \n";
	b.childerm(42);
	cout << "\n --- \n";
	b.childerm(23);

}