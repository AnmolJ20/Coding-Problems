//
//  main.cpp
//  Domino
//
//  Created by Anmol Jain on 27/08/19.
//  Copyright © 2019 Anmol Jain. All rights reserved.
//

// You are given an string representing the initial conditions of some 
// dominoes. Each element can take one of three values:

// L, meaning the domino has just been pushed to the left,
// R, meaning the domino has just been pushed to the right, or
// ., meaning the domino is standing still.
// Determine the orientation of each tile when the dominoes stop falling. 
// Note that if a domino receives a force from the left and right side simultaneously, 
// it will remain upright.

// For example, given the string .L.R....L, you should return LL.RRRLLL.

// Given the string ..R...L.L, you should return ..RR.LLLL.

#include <iostream>
#include <string>

std::string finalState(std::string initialState);
void makeRight(std::string &string, int index, int number);
void makeLeft(std::string &string, int index, int number);

int main(int argc, const char * argv[]) {
    std::string initialState;
    std::cin >> initialState;
    
    std::cout << finalState(initialState) << std::endl;
}

std::string finalState(std::string initialState) {
    int size = (int)initialState.size();
    int count = 0;
    
    for (int i = 0; i < size; i++) {
        
        if (initialState[i] == 'L') {
            makeLeft(initialState, i, count);
            count = 0;
        }
        
        else if (initialState[i] == 'R') {
            int j = i+1;
            count = 0;
            while (j < size) {
                if (initialState[j] == 'L') {
                    int move = j - i;
                    move = (move % 2 == 0) ? (move-1)/2 : move/2;
                    
                    makeLeft(initialState, j, move);
                    makeRight(initialState, i, move);
                    break;
                }
                
                count++;
                j++;
            }
            
            if (j == size) {
                makeRight(initialState, i, count);
            }
            
            i = j;
            count = 0;
        }
        
        else {
            count++;
        }
    }
    
    return initialState;
}

void makeRight(std::string &string, int index, int number) {
    for (int i = index+1; number != 0; i++, number--) {
        string[i] = 'R';
    }
}

void makeLeft(std::string &string, int index, int number) {
    for (int i = index-1; number != 0; i--, number--) {
        string[i] = 'L';
    }
}
