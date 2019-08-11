//
//  main.cpp
//  ColorSorter
//
//  Created by Anmol Jain on 11/08/19.
//  Copyright © 2019 Anmol Jain. All rights reserved.
//

// Given an array of strictly the characters 'R', 'G', and 'B',
// segregate the values of the array so that all the Rs comes
// first, the Gs come second, and the Bs comes last.
// You can only swap elements of the array.

// Do this in linear time and in-place.

// For e.g., given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'], it
// should become ['R', 'R', 'R', 'G', 'G', 'B', 'B'].

#include <iostream>
#include <vector>

void sort(std::vector<char>& input);

int main() {
    std::vector<char> input;
    int noOfColors; char in;
    std::cin >> noOfColors;
    
    for (int i = 0; i < noOfColors; i++) {
        std::cin >> in;
        input.push_back(in);
    }
    
    sort(input);
    
    std::cout << std::endl;
    for (char item : input) {
        std::cout << item << " ";
    }
    
    std::cout << std::endl;
    
    return 0;
}

void sort(std::vector<char>& input) {
    char temp;
    for (int i = 0; i < input.size()-1; i++) {
        for (int j = 0; j < input.size()-i-1; j++) {
            if (input[j] < input[j+1]) {
                temp = input[j];
                input[j] = input[j+1];
                input[j+1] = temp;
            }
        }
    }
}
