//
//  main.cpp
//  FixedPoint
//
//  Created by Anmol Jain on 27/08/19.
//  Copyright © 2019 Anmol Jain. All rights reserved.
//

// A fixed point in an array is an element whose value is equal to its index.
// Given a sorted array of distinct elements, return a fixed point, if one exists.
// Otherwise, return False.
//
// For example, given [-6, 0, 2, 40], you should return 2.
// Given [1, 5, 7, 8], you should return False.

#include <iostream>
#include <vector>

int findFixedPoint(std::vector<int> array);

int main(int argc, const char * argv[]) {
    int size, input;
    std::vector<int> array;
    std::cin >> size;
    for (int i = 0; i < size; i++) {
        std::cin >> input;
        array.push_back(input);
    }
    
    int answer = findFixedPoint(array);
    if (answer != -1)
        std::cout << answer << std::endl;
    else
        std::cout << "False" << std::endl;
    return 0;
}

int findFixedPoint(std::vector<int> array) {
    int next;
    for (int i = 0; i < array.size();) {
        if (i == array.at(i))
            return i;
        
        next = array.at(i+1);
        
        if (next < 0 or next < i)
            i++;
        else
            i = next;
    }
    
    return -1;
}
