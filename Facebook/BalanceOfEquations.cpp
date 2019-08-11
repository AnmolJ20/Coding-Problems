//
//  main.cpp
//  paranthesis
//
//  Created by Anmol Jain on 11/08/19.
//  Copyright © 2019 Anmol Jain. All rights reserved.

// Given a string of round, curly, and square open and
// closing brackets, return whether the brackets are
// balanced (well-formed).

// For E.g., given the string "([])[]({})", you should
// return true.

// Given the string "([)]" or "((()", you should return false

#include <iostream>
#include <stack>
#include <set>
#include <utility>

bool validateParanthesis(std::string input);

int main() {
    std::string input;
//    std::cin >> input;
    std::getline(std::cin, input);
    
    std::cout << std::boolalpha << validateParanthesis(input) << std::endl;
    return 0;
}

bool validateParanthesis(std::string input) {
    std::stack<char> stackOfParanthesis;
    std::set<char> openingParanthesis;
    openingParanthesis.insert('(');
    openingParanthesis.insert('[');
    openingParanthesis.insert('{');
    std::set<char> closingParanthesis;
    closingParanthesis.insert(')');
    closingParanthesis.insert(']');
    closingParanthesis.insert('}');
    
    for (char bracket : input) {
        if (openingParanthesis.find(bracket) != openingParanthesis.end()) {
            stackOfParanthesis.push(bracket);
        }
        
        else if (closingParanthesis.find(bracket) != closingParanthesis.end() and !stackOfParanthesis.empty()) {
            if (bracket == ')' and stackOfParanthesis.top() == '(') {
                stackOfParanthesis.pop();
            } else if (bracket == ']' and stackOfParanthesis.top() == '[') {
                stackOfParanthesis.pop();
            } else if (bracket == '}' and stackOfParanthesis.top() == '{') {
                stackOfParanthesis.pop();
            } else {
                return false;
            }
        }
    }
    
    if (!stackOfParanthesis.empty()) {
        return false;
    }
    
    return true;
}
