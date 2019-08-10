// Given an array of integers and a number k, where 1 <= k <= length
// of the array, compute the maximum values of each subarray of length k.
// For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should 
// get: [10, 7, 8, 8], since:
//	- 10 = max(10, 5, 2)
//	- 7 = max(5, 2, 7)
//	- 8 = max(2, 7, 8)
//	- 8 = max(7, 8, 7)

// Do this in O(n) time and O(k) space. You can modify the input array
// in-place and you do not need to store the results. You can simply print
// them out as you compute them.

#include <iostream>
#include <vector>
#include <set>

void printMax(const std::vector<int> &inputArray, int k);

int main() {
    int k;
    std::cin >> k;
    std::vector<int> inputArray;
    int input;
    for (int i = 0; i < k; i++) {
        std::cin >> input;
        inputArray.push_back(input);
    }

    std::cin >> k;

    printMax(inputArray, k);
}

void printMax(const std::vector<int> &inputArray, int k) {
    std::set<int> maxData;
    for (int i = 0; i < k-1; i++) {
        maxData.insert(inputArray[i]);
    }

    for (int i = k-1; i < inputArray.size(); i++) {
        maxData.insert(inputArray[i]);
        std::cout << *maxData.rbegin() << std::endl;
        maxData.erase(inputArray[i-2]);
    }
}