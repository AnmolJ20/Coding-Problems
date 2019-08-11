//
//  main.cpp
//  TrapWaterCounter
//
//  Created by Anmol Jain on 11/08/19.
//  Copyright © 2019 Anmol Jain. All rights reserved.
//

// You are given an array of non-negative integers that
// represents a two-dimensional elevation map where
// each element is unit-width wall and the integer is the
// height. Suppose it will rain and all spots between two
// walls get filled up.

// Compute how many units of water remain trapped on
// the map in O(N) time and O(1) space.

// For e.g., given the input [2, 1, 2], we can hold 1
// unit of water in the middle.

// Given the input [3, 0, 1, 3, 0, 5], we can hold 3 units in
// the first index, 2 in the second, and 3 in the fourth
// index (we cannot hold 5 since it run off to the
// left), so we can trap 8 units of water.

#include <iostream>
#include <vector>

int trappedWater(std::vector<int> walls) {
    
    int result = 0;
    int left_max = 0, right_max = 0;
    int lo = 0, hi = (int)(walls.size())-1;
    
    while(lo <= hi) {
        if(walls[lo] < walls[hi]) {
            if(walls[lo] > left_max)
                left_max = walls[lo];
            else
                result += left_max - walls[lo];
            lo++;
        }
        else {
            if(walls[hi] > right_max)
                right_max = walls[hi];
            else
                result += right_max - walls[hi];
            hi--;
        }
    }
    
    return result;
}

int main()
{
    std::vector<int> walls;
    int noOfWalls;
    std::cin >> noOfWalls;
    int input;
    for (int i = 0; i < noOfWalls; i++) {
        std::cin >> input;
        walls.push_back(input);
    }
    
    std::cout << trappedWater(walls) << std::endl;
}
