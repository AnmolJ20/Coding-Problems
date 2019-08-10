//
//  main.cpp
//  snapchar
//
//  Created by Anmol Jain on 11/08/19.
//  Copyright © 2019 Anmol Jain. All rights reserved.
//

// Given an array of time intervals (start, end)for classroom
// lectures (possibly overlapping).
// Find the minimum number of room required.

// E.g. Given [(20, 75), (0, 50), (60, 150)], you should return 2.

#include <iostream>
#include <utility> //make_pair
#include <queue> //min_heap
#include <set> //set

class FirstCompare {
public:
    bool operator()(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs ) const
    { return lhs.first < rhs.first; }
};

class SecondCompare {
public:
    bool operator()(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) const
    { return lhs.second > rhs.second; }
};

int maxClasses(std::set<std::pair<int, int>, FirstCompare> classes);

int main() {
    int noOfClasses;
    std::cin >> noOfClasses;
    if (noOfClasses <= 0)
        return 1;
    
    std::set<std::pair<int, int>, FirstCompare> classes;
    int x, y;
    for (int i = 0; i < noOfClasses; i++) {
        std::cin >> x >> y;
        classes.insert(std::make_pair(x, y));
    }
    
    std::cout << maxClasses(classes) << std::endl;
    return 0;
}

int maxClasses(std::set<std::pair<int, int>, FirstCompare> classes) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, SecondCompare> classesInProgress;
    classesInProgress.push(*classes.begin());
    classes.erase(*classes.begin());
    int maxClass = 1;
    int classesInUse = 1;
    
    for (std::pair<int, int> Class : classes) {
        std::pair<int, int> nextClass = Class;
        if (nextClass.first > classesInProgress.top().second) {
            while (classesInProgress.top().second <= nextClass.first && !classesInProgress.empty()) {
                classesInProgress.pop();
                classesInUse--;
            }
        }

        classesInUse++;
        if (classesInUse > maxClass)
            maxClass = classesInUse;
        classesInProgress.push(nextClass);
    }
    
    return maxClass;
}

