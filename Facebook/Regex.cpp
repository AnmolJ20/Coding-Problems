//
//  main.cpp
//  regex
//
//  Created by Anmol Jain on 11/08/19.
//  Copyright © 2019 Anmol Jain. All rights reserved.
//

// Implement regular expression matching with the following special charcaters:
//    - .(period) which matches any single character
//    - *(asterisk) which matches zero or more of the preceding element

// That is, implement a function that takes in a string and a valid regular
// expression and returns whether or not the string matches the regular
// expression.

// E.g., gievn the regular expression "ra." and the string "ray", your
// function should return true. The same regular expression on the string
// "raymond" should return false.

// Given the regular expression ".*at" and the string "chat", your function
// should return true. The same regular expression on the string "chats" should
// return false.


#include <iostream>
using namespace std;

bool regexMatch(char str[], char pattern[]) {
    if (*str == '\0' && *pattern == '\0')
        return true;
    
    if (*pattern == '\0')
        return false;
    
    if (*str == '\0') {
        if (*pattern == '*')
            return regexMatch(str, pattern + 1);
        return false;
    }
    
    if (*pattern == '.' or *pattern == *str)
        return regexMatch(str + 1, pattern + 1);
    
    if (*pattern == '*'){
        return
        /* '*' matches zero char in the string*/
        regexMatch(str, pattern + 1) or
        /* '*' matches AT LEAST ONE char in the string */
        regexMatch(str + 1, pattern);
    }
    return false;
}


int main() {
    char pattern[100], str[100];
    cin >> str >> pattern;
    bool ans = regexMatch(str, pattern);
    cout << std::boolalpha << ans << std::endl;
}
