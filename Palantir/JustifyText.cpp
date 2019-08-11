//
//  main.cpp
//  JustifyText
//
//  Created by Anmol Jain on 11/08/19.
//  Copyright © 2019 Anmol Jain. All rights reserved.
//

// Write a algorithm to justify text. Given a sequence of
// words and an integer line length k, return a list of
// strings which represents each line, fully justified.

// More specifically, you should have as many words as
// possible in each line. There should be atleast one
// space between each word. Pad extra spaces when
// necessary so that each line has exactly length k.
// Spaces should be distributed as equally as possible,
// with the extra spaces, if any, distributed starting from
// the left.

// If you can only fit one word on a line, then you should
// pad the right-hand side with spaces.

// Each word is guaranteed not to be longer than k.

// For e.g., given the list of words ["the", "quick",
// "brown", "fox", "jumps", "over", "the", "lazy", "dog"] and k
// = 16, you should return the following:

// ["the  quick brown", # 1 extra space on the left
//  "fox  jumps  over", # 2 extra spaces distributed evenly
//  "the   lazy   dog"] # 4 extra spaces distributed evenly

#include <iostream>
#include <string>
#include <vector>

std::string justifyText(std::vector<std::string> words, int k);
std::string addSpaces(std::vector<std::string>, int spaces);

int main() {
    std::vector<std::string> input;
    std::string inputString;
    int kLength;
    
    
    std::cin >> kLength;
    for (int i = 0; i < kLength; i++) {
        std::cin >> inputString;
        input.push_back(inputString);
    }
    
    std::cin >> kLength;
    
    std::cout << justifyText(input, kLength) << std::endl;
    
    return 0;
}

std::string justifyText(std::vector<std::string> words, int k) {
    std::vector<std::string> line;
    std::string answer = "";
    int length = 0;
    for (std::string word : words) {
    start:
        if (word.size() + length <= k) {
            line.push_back(word);
            length += word.size() + 1;
        } else {
            answer += addSpaces(line, k - length + 1);
            answer += "\n";
            length = 0;
            line.clear();
            goto start;
        }
    }
    
    answer += addSpaces(line, k - length + 1);
    answer += "\n";
    
    return answer;
}

std::string addSpaces(std::vector<std::string> line, int spaces) {
    std::string answer = "";
    
    if (line.size() == 1) {
        answer += line[0];
        for (int i = 0; i < spaces; i++)
            answer += " ";
        return answer;
    }
    
    for (int i = 0; i < line.size()-1; i++) {
        line[i] += " ";
    }
    
    for (int i = 0; i < line.size()-1 && spaces > 0; i = ((i + 1) % (line.size()-1)), spaces--) {
        line[i] += " ";
    }
    
    for (std::string word : line) {
        answer += word;
    }
    
    return answer;
}
