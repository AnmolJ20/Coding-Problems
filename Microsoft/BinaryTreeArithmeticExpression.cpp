//
//  main.cpp
//  BinaryTreeArithmeticExpression
//
//  Created by Anmol Jain on 12/08/19.
//  Copyright © 2019 Anmol Jain. All rights reserved.
//

// Suppose an arithmetic expression is given as a binary
// tree. Each leaf is an integer and each internal node is
// one of '+', '-', '*', or '/'.

// Given the root to such a tree, write a function to
// eveluate it.

// For e.g., given the following tree:
/*
         *
        / \
       +   +
      / \ / \
     3  2 4  5
 */

#include <iostream>
#include <exception>

enum Operator {
    plus, minus, multiply, divide
};

std::ostream& operator<<(std::ostream& os, Operator c) {
    switch(c) {
        case plus:
            os << "plus";
            break;
        case minus:
            os << "minus";
            break;
        case multiply:
            os << "multiply";
            break;
        case divide:
            os << "divide";
            break;
    }
    return os;
}

struct node {
    bool leaf;
    Operator symbol;
    int value;

    node *left;
    node *right;

    node(int n) : value(n) {
        left = right = nullptr;
    }
    
    node(Operator n) : symbol(n) {
        left = right = nullptr;
    }

    ~node() {
        delete left;
        delete right;
    }

    template<typename T>
    void init(T input) {
        if (typeid(input) == typeid(Operator)) {
            leaf = false;
            symbol = input;
        }
        else if (typeid(input) == typeid(int)){
            leaf = true;
            value = input;
        }
    }

};

node *makeTree();
int evaluate(node *root);

int main() {
    node *expression = makeTree();
    std::cout << evaluate(expression) << std::endl;
}

node *makeTree() {
    std::string input;
    std::cin >> input;
    node *ptr;
    try {
        ptr = new node(std::stoi(input));
    }
    catch (const std::exception& e) {
        if (input == "plus")
            ptr = new node(plus);
        else if (input == "minus")
            ptr = new node(minus);
        else if (input == "multiply")
            ptr = new node(multiply);
        else if (input == "divide")
            ptr = new node(divide);
        else if (input == "end")
            return nullptr;
    }
    
    ptr->left = makeTree();
    ptr->right = makeTree();
    
    return ptr;
}

int evaluate(node *root) {
    if (root->left == nullptr and root->right == nullptr) {
        return root->value;
    }
    
    int left = evaluate(root->left);
    int right = evaluate(root->right);
    
    switch(root->symbol) {
        case plus:
            return left + right;
        case minus:
            return left - right;
        case multiply:
            return left * right;
        case divide:
            return left / right;
    }
}


// makeTree() takes input in preorder style
/*
 
 //input for tree given in example above
 multiply
 plus
 3 end end
 2 end end
 plus
 4 end end
 5 end end
 
 */
