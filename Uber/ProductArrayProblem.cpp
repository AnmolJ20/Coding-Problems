// Given an array of integers, return a new array such that
// each element at index i of the new array is the 
// product of all the numbers in the original array except the one at i.

// E.g. if our input was [1, 2, 3, 4, 5], the expected 
// output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], 
// the expected output would be [2, 3, 6].

// Follow-up: what is we can't use division?

#include <iostream>
#include <vector>

std::vector<int> compute(std::vector<int> input);

int main() {
	std::vector<int> input;
	int n; std::cin >> n;
	int in;

	for (int i = 0; i < n; ++i) {
		std::cin >> in;
		input.push_back(in);
	}

	std::vector<int> answer = compute(input);

	for (int i : answer) {
		std::cout << i << ' ';
	}
}

std::vector<int> compute(std::vector<int> input) {
	int size = input.size();
	std::vector<int> v(size, 1);
	int temp = 1;

	for (int i = 0; i < size; i++) {
		v.at(i) = temp;
		temp *= input.at(i);
	}

	temp = 1;
	for (int i = size - 1; i >= 0; i--) {
		v.at(i) *= temp;
		temp *= input.at(i);
	}

	return v;
}
