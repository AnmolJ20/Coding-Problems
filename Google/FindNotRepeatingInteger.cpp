// Given an array of integers where every integer occurs
// three times except for one integer, which only occurs 
// once, find and return the non-duplicated integer.

// For e.g., given [6, 1, 3, 3, 3, 6, 6], return 1. Given 
// [13, 19, 13, 13], return 19.

// Do this in O(N) time and O(1) space.

#include <iostream>
#include <algorithm>
#include <array>

int main() {
	int n; std::cin >> n;
	int input[n];

	for (int i = 0; i < n; i++) {
		std::cin >> input[i];
	}

	std::sort(input, input+n);

	for (int i = 0; i < n; i++) {
		if (input[i] == input[i+1]) {
			i += 2;
			continue;
		}

		else 
			std::cout << "Answer: " << input[i];
	}
}