// A unival tree (which stands for 'universal value') is a 
// tree where all nodes under it have the same value.

// Given the root to a binary tree, count the number of 
// unival subtrees.

// E.g. the following tree has 5 unival subtrees:

/*
	  0
	 / \
	1   0
	   / \
	  1   0
	 / \
	1   1
   / \
  0   1
*/

#include <iostream>
#include <climits>
#include <cmath>
#include <queue>
#include <map>

struct node {
	int value;
	node *left;
	node *right;

	node(int in) 
		: value(in) {}
};

int count = 0;
node * __init__() {
	int input;
	std::cin >> input;
	if (input == -1)
		return nullptr;
	node *root = new node(input);
	root->left = __init__();
	root->right = __init__();
	return root;
}

void print(node *root) {
	std::queue<node*> q;
	q.push(root);
	q.push(nullptr);

	while (1) {
		node *front = q.front();
		q.pop();
		if (front) {
			if (front->left)
				q.push(front->left);
			if (front->right)
				q.push(front->right);
			std::cout << front->value << ' ';
		}

		else {
			if (q.empty())
				break;
			else {
				std::cout << '\n';
				q.push(nullptr);
			}
		}
	}
}

int unival_count(node *root) {
	if (!root->left and !root->right) {
		count++;
		return root->value;
	}

	int left = unival_count(root->left);
	int right = unival_count(root->right);
	if (left == right)
		count++;

	return root->value;
}

int main() {
	node *root = __init__();
    unival_count(root);
	std::cout << "tree have " << count << " unival subtrees\n";
}
