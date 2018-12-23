// There exists a staircase with N steps, and you can 
// climb up either 1 or 2 steps at a time. Given N, wrote a 
// function that returns the number of unique ways you 
// can climb the staircase. The order of the steps matters.

/*
	E.g. if N is 4, then there are 5 unique ways:

		- 1, 1, 1, 1
		- 2, 1, 1
		- 1, 2, 1
		- 1, 1, 2
		- 2, 2
*/

#include <iostream>
#include <algorithm>

int nWays(int n) {
	int* dp = new int[n + 1];
	std::fill(dp, dp + n + 2, 0);

	dp[0] = 1;
	dp[1] = 1;

	for (int nStair = 2; nStair <= n; nStair++) {
		dp[nStair] = dp[nStair - 1] + dp[nStair - 2];
	}

	int ans = dp[n];
	delete [] dp;
	return ans;
}

int main() {
	Timing T;
	int n = 45;
	std::cout << nWays(n) << std::endl;
}
