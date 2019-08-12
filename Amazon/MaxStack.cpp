//
//  main.cpp
//  MaxStack
//
//  Created by Anmol Jain on 12/08/19.
//  Copyright © 2019 Anmol Jain. All rights reserved.
//

// Implement a stack that has the following methods:
//     - push(val), which pushes an element onto the stack
//     - pop(), which pops off and returns the topmost
//         element of the stack. If there are no elements in
//         the stack, then it should throw an error or return null.
//     - max(), which returns the maximum value in the
//         stack currently. If there are no elements in the
//         stack, then it should throw an error or return null.

// Each method should run in constant time.

#include <iostream>
#include <vector>

class SpecialStack {
    std::vector<int> stack;
    std::vector<int> maxNum;
public:
    SpecialStack();
    
    int max();
    int top();
    int pop();
    void push(int value);
};

int main() {
    SpecialStack st;
    st.push(100);
    st.push(20);
    st.push(30);
    std::cout << "min " <<st.max() << std::endl;
    std::cout << "top " << st.top() << std::endl;
    st.pop();
    std::cout << "top " << st.top() << std::endl;
    std::cout << "min " << st.max() << std::endl;
    st.pop();
    std::cout << "min " << st.max() << std::endl;
}

SpecialStack::SpecialStack() {
    stack.reserve(10);
}

int SpecialStack::top() {
    return stack.at(stack.size()-1);
}

int SpecialStack::pop() {
    int rtn = top();
    if (top() == max()) {
        maxNum.pop_back();
    }
    
    stack.pop_back();
    return rtn;
}

void SpecialStack::push(int value) {
    stack.push_back(value);
    if (stack.size() == 1)
        maxNum.push_back(value);
    else if (value > max() || value == max())
        maxNum.push_back(value);
}

int SpecialStack::max() {
    return maxNum.at(maxNum.size()-1);
}
