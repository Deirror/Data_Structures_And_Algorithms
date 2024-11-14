#include <iostream>
#include <queue>

struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int data, TreeNode* left = nullptr, TreeNode* right = nullptr) 
		: data(data), left(left), right(right) {}
};

class BTS {
	TreeNode* root;
	void _inorderTraversal(TreeNode* root) const {
		if (!root) {
			return;
		}

		_inorderTraversal(root->left);
		std::cout << root->data;
		_inorderTraversal(root->right);
	}

	TreeNode** findMin(TreeNode** subroot) {
		while ((*subroot)->left) {
			subroot = &(*subroot)->left;
		}
		return subroot;
	}
public:
	BTS() : root(nullptr) {}

	bool contains(int target) const {
		TreeNode* curr = root;
		while (curr) {
			if (curr->data < target) {
				curr = curr->right;
			}
			else if (target < curr->data) {
				curr = curr->left;
			}
			else {
				return true;
			}
		}
		return false;
	}

	void insert(int data) {
		TreeNode** curr = &root;
		while (*curr) {
			if ((*curr)->data < data) {
				curr = &(*curr)->right;
			}
			else if (data < (*curr)->data) {
				curr = &(*curr)->left;
			}
		}
		*curr = new TreeNode(data); 
	}

	void inorderTraversal() const {
		_inorderTraversal(this->root);
	}

	void levelOrderTraversal() const {
		TreeNode* curr = root;
		std::queue<TreeNode*> q;
		q.push(root);
		while (q.size()) {
			TreeNode* temp = q.front();
			q.pop();
			std::cout << temp->data << ' ';
			if (temp->left) {
				q.push(temp->left);
			}
			if (temp->right) {
				q.push(temp->right);
			}
		}
	}

	void remove(int val) {
		TreeNode** curr = &root;

		while (*curr) {
			if ((*curr)->data < val) {
				curr = &(*curr)->right;
			}
			else if (val < (*curr)->data) {
				curr = &(*curr)->left;
			}
			else {
				break;
			}
		}

		if (*curr == nullptr) {
			return;
		}

		TreeNode* to_remove = *curr;

		if (!to_remove->left && !to_remove->right) {
			*curr = nullptr;
		}
		else if (to_remove->left && !to_remove->right) {
			*curr = to_remove->left;
		}
		else if (!to_remove->left && to_remove->right) {
			*curr = to_remove->right;
		}
		else {
			TreeNode** minInRightBST = findMin(&to_remove->right);

			*curr = *minInRightBST;
			*minInRightBST = (*minInRightBST)->right;

			(*curr)->left = to_remove->left;
			(*curr)->right = to_remove->right;

		}
		delete to_remove;
	}
};

int main() {
	BTS bts;
	bts.insert(1);
	bts.insert(2);
	bts.insert(10);
	bts.insert(11);
	bts.insert(5);
	bts.insert(4);
	bts.insert(0);
	bts.insert(-1);

	bts.remove(0);
	bts.remove(1);

	//bts.inorderTraversal();
	bts.levelOrderTraversal();

	return 0;
}
