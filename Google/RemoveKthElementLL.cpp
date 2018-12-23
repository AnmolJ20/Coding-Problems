// Given a singly linked list and an integer k, remove the
// kth last element from the list. k is guaranteed to be 
// smaller than the length of the list.

// The list is very long, so making more than one pass is
// prohibitively expensive.

// Do this in constant space and in one pass

#include <iostream>

struct Node {
	int value;
	Node *next;

	Node() : value(0), next(nullptr) {}
	Node(int k) : value(k), next(nullptr) {}
	~Node() {
		delete next;
	}
};

void remove(Node *head, int k) {
	Node *to_be_removed, *tail, *mover;
	mover = head;

	for (int i = 1; i < k; i++) {
		mover = mover->next;
	}

	tail = nullptr;
	to_be_removed = head;
	while (mover->next != nullptr) {
		tail = to_be_removed;
		to_be_removed = to_be_removed->next;
		mover = mover->next;
	}

	tail->next = to_be_removed->next;
	to_be_removed->next = nullptr;
	delete to_be_removed;
}

Node* list(int n) {
	Node *head = new Node(0);
	Node *temp = head;
	for (int i = 1; i < n; i++) {
		temp->next = new Node(i);
		temp = temp->next;
	}

	return head;
}

void print(Node *head) {
	Node *temp = head;
	while (temp != nullptr) {
		std::cout << temp->value << "  ";
		temp = temp->next;
	}
}

int main() {
	Node *head = list(1000);
	print(head);
	std::cout << "\n----------\n";
	remove(head, 10);
	// print(head);
	delete head;
}
