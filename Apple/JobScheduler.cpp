// Implement a job scheduler which takes in a function f
// and an integer n, and calls f after n milliseconds.

#include <iostream>
#include <windows.h>
#include <chrono>

class Timing {
	std::chrono::time_point<std::chrono::high_resolution_clock> start;
	std::chrono::time_point<std::chrono::high_resolution_clock> end;
	std::chrono::duration<float> duration;
public:
	Timing() {
		start = std::chrono::high_resolution_clock::now();
	}

	~Timing() {
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		std::cout << duration.count() << std::endl;
	}
};

void scheduler(void (*f)(int), int n);

int main() {
	Timing T;
	int n = 0;
	auto f = [](int n){ std::cout << n << "\n"; };

	scheduler(f, n);
}

void scheduler(void (*f)(int), int n) {
	Sleep(n);
	f(n);
}
