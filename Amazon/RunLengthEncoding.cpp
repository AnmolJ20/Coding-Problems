//
//  main.cpp
//  RunLengthEncoding
//
//  Created by Anmol Jain on 11/08/19.
//  Copyright © 2019 Anmol Jain. All rights reserved.
//

// Run-length encoding is a fast and simple method of
// encoding strings. The basic idea is to represent
// repeated successive characters as a single count and
// character. For e.g., the string "AAAABBBCCDAA"
// would be encoded as "4A3B2C1D2A"

// Implement run-length encoding and decoding. You
// can assum the string to be encoded have no digits
// and consists solely of alphabetic characters. You can
// assume the string to be decoded is valid.

#include <iostream>
#include <string>

std::string runLengthEncoder(std::string input);

int main() {
    std::string input;
    std::cin >> input;
    
    std::cout << runLengthEncoder(input) << std::endl;
    return 0;
}

std::string runLengthEncoder(std::string input) {
    int count = 1;
    char currentLetter = input[0];
    std::string answer = "";
    
    for (int i = 1; i < input.size(); i++) {
        if (currentLetter == input[i]) {
            count++;
        } else {
            answer += std::to_string(count);
            answer += currentLetter;
            count = 1;
            currentLetter = input[i];
        }
    }
    
    answer += std::to_string(count);
    answer += currentLetter;
    
    return answer;
}
