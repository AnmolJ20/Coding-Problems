// Given a list of numbers and a number k, return whether any two numbers
// from the list add up to k.
// E.g. given [10, 15, 3, 7] and k of 17
// return truw since 10 + 7 is 17.

// upgrade: Do this in one pass

#include <iostream>
#include <algorithm>
#include <vector>

bool sum_exist(const std::vector<int>& input, int sum);

int main() {
	std::vector<int> input;
	int n, in, k;
	std::cin >> n;
	while (n > 0) {
		std::cin >> in;
		input.push_back(in);
	}

	std::cin >> k;

	std::cout << (sum_exist(input, sum) ? "Do Exist" : "Do Not Exist") << std::endl;
}

bool sum_exist(std::vector<int> input, int k) {
	std::sort(input.begin(), input.end());
	int i = 0, j = input.size() - 1;
	int sum;
	while (i < j) {
		sum = input[i] + input[j];
		if (sum == k)
			return true;
		else if (sum < k)
			i++;
		else
			j--;
	}

	return false;
}
