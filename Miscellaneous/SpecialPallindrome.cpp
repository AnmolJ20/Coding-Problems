//Pallindrome++ - Check if a string is pallindrome or not
//string can contain any character but all the symbols and whitespaces are ignored while checking for pallindrome
//in short, we will only check alphabets & numbers while calculating the pallindrome

//input - first line, t, number of test cases
//after that every t lines are string input
//print YES if a string is pallindrome & NO if it is not a pallindrome

#include <iostream>
#include <limits>
#include <string>
#include <cctype>

void Pallindrome(std::string input_strings[], int n);
bool check_pallindrome(std::string input_string);

int main() {
	int test_cases;
	std::cin >> test_cases;
	std::string input_strings[test_cases];

	//used to remove trailing '\n' from the stream
	//which was left from the line 'std::cin >> test_cases;'
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	for (int i = 0; i < test_cases; ++i) {
		std::getline(std::cin, input_strings[i]);
	}

	Pallindrome(input_strings, test_cases);
}

void Pallindrome(std::string input_strings[], int n) {
	for (int i = 0; i < n; i++) {
		std::cout << (check_pallindrome(input_strings[i]) ? "YES" : "NO") << std::endl;
	}
}

bool check_pallindrome(std::string input_string) {
	for (int i = 0, j = input_string.size(); i < j;) {
		if (isalnum(input_string[i])) {
			if (isalnum(input_string[j])) {
				if (input_string[i] == input_string[j]) {
					i++; j--;
				}

				else
					return false;
			}

			else
				j--;
		}

		else
			i++;
	}

	return true;
}
