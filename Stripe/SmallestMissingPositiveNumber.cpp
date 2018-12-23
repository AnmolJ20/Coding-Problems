//Find the smallest positive number missing in the given input array
//array can have duplicates as well as negative values
// if array is [1, 2, -1, 0, 1] answer should be 3 as it is the smallest postive integer missing in the array

// Complexities - Time = O(n), Space = O(1)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int smallest_missing_positive(std::vector<int> input);

int main() {
	std::vector<int> input;
	int n, in;
	std::cin >> n;

	while (n) {
		std::cin >> in;
		input.push_back(in);
		--n;
	}

	int answer = smallest_missing_positive(input);

	std::cout << "Smallest Missing Positive Integer: " << answer << std::endl;
}

int smallest_missing_positive(std::vector<int> input) {
	input.erase(std::remove_if(input.begin(), input.end(), [](int i){ return i < 1; }), input.end());

	int size = input.size();

	for (int i = 0; i < size; i++) {
		if (abs(input[i]) - 1 < size && input[abs(input[i]) - 1] > 0)
			input[abs(input[i]) - 1] = -input[abs(input[i]) - 1];
	}

	for (int i = 0; i < size; i++) {
		if (input[i] > 0)
			return i + 1;
	}

	return size + 1;
}
