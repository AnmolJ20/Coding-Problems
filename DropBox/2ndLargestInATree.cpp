//
//  main.cpp
//  2ndLargestInTree
//
//  Created by Anmol Jain on 12/08/19.
//  Copyright © 2019 Anmol Jain. All rights reserved.
//

// Given the root to a binary search tree, find the second
// largest node in the tree.

#include <iostream>

struct node {
    int data;
    node *left;
    node *right;
    node(int n) : data(n) { left = right = nullptr; }
    ~node() {
        delete left;
        delete right;
    }
};

std::pair<int, int> largest2(node *root);
int secondLargest(node *root);
node *makeTree();

int main() {
    node *root = makeTree();
    std::cout << secondLargest(root) << std::endl;
}

std::pair<int, int> largest2(node *root) {
    if (root->left == nullptr and root->right == nullptr) {
        return std::make_pair(root->data, -1);
    }
    
    std::pair<int, int> left = largest2(root->left);
    std::pair<int, int> right = largest2(root->right);
    
    if (right.first > root->data and right.first > left.first) {
        return std::make_pair(right.first, std::max(root->data, std::max(left.first, right.second)));
    }
    else if (left.first > root->data and left.first > right.first) {
        return std::make_pair(left.first, std::max(root->data, std::max(right.first, left.second)));
    }
    else {
        return std::make_pair(root->data, std::max(left.first, right.first));
    }
}

int secondLargest(node *root) {
    return largest2(root).second;
}

node *makeTree() {
    int input;
    std::cin >> input;
    if (input == -1)
        return nullptr;
    node *ptr = new node(input);
    ptr->left = makeTree();
    ptr->right = makeTree();
    return ptr;
}
