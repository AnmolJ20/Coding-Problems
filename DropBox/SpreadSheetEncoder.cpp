// Spreadsheets often use this alphabetical encoding for its columns: 
// "A", "B", "C", ..., "AA", "AB", ..., "ZZ", "AAA", "AAB", ....

// Given a column number, return its alphabetical column id. For 
// example, given 1, return "A". Given 27, return "AA".

#include <iostream>
#include <string>
#include <algorithm>

void increment(std::string& str, int index) {
    if (index >= 6) 
        return;

    if (str[index] == ' ')
        str[index] = 'A';
    else if (str[index] == 'Z') {
        str[index] = 'A';
        increment(str, index+1);
    }

    else {
        str[index]++;
    }
}

int main() {
    int input;
    std::cin >> input;
    if (input > 321272406 or input < 0) {
        std::cout << "Not in range" << std::endl;
        return 0;
    }

    std::string answer = "       ";
    for (int i = 0; i < input; i++)
        increment(answer, 0);

    std::reverse(answer.begin(), answer.end());
    answer.erase(std::remove_if(answer.begin(), answer.end(), ::isspace), answer.end());
    std::cout << answer << std::endl;   
}