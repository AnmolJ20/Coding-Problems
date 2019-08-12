//
//  main.cpp
//  Add2SpecialLinkedList
//
//  Created by Anmol Jain on 12/08/19.
//  Copyright © 2019 Anmol Jain. All rights reserved.
//

// Let's represent an integer in a linked list format by having each node represent a digit in the
// number. The nodes make up the number in reversed order.

// For example, the following linked list:
// 1 -> 2 -> 3 -> 4 -> 5
// is the number 54321.

// Given two linked lists in this format, return their sum in the same linked list format.
// For example, given
// 9 -> 9
// 5 -> 2

// return 124 (99 + 25) as:
// 4 -> 2 -> 1

#include <iostream>

struct Node {
    int data;
    Node *next;
    Node() {next = nullptr;}
};

Node* intToNode(int number);
int nodeToInt(Node *first);
Node* add(Node* first, Node* second);

std::ostream& operator<<(std::ostream& os, Node *c) {
    while (c->next != nullptr) {
        os << c->data << " ";
        c = c->next;
    }
    return os;
}

int main() {
    Node *number100 = intToNode(25);
    Node *number1 = intToNode(446);
    Node *number100plusnumber1 = add(number100, number1);
    std::cout << number100plusnumber1 << std::endl;
}

Node* intToNode(int number) {
    Node* head = new Node;
    Node* mover = head;
    while (number != 0) {
        mover->data = number % 10;
        number /= 10;
        mover->next = new Node;
        mover = mover->next;
    }
    
    return head;
}

Node* add(Node* first, Node* second) {
    int curNum;
    bool carry = false;
    Node *third = new Node;
    Node *mover = third;
    while(first->next != nullptr && second->next != nullptr) {
        curNum = first->data + second->data;
        curNum += carry;
        carry = (curNum > 10) ? true : false;
        if(carry) {
            curNum -= 10;
        }
        mover->data = curNum;
        mover->next = new Node;
        mover = mover->next;
        first = first->next;
        second = second->next;
    }
    
    while (first->next != nullptr) {
        mover->data = carry + first->data;
        mover->next = new Node;
        mover = mover->next;
        first = first->next;
    }
    
    while (second->next != nullptr) {
        mover->data = carry + second->data;
        mover->next = new Node;
        mover = mover->next;
        second = second->next;
    }
    
    return third;
}
