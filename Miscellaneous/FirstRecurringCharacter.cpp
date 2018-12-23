// Print the first recurring charcter in a string 

#include <iostream>
#include <string>
#include <set>

char first_recurring_character(std::string nString);

int main() {
	std::string nString;
	std::getline(std::cin, nString);

	std::cout << first_recurring_character(nString) << std::endl;
}

char first_recurring_character(std::string nString) {
	std::set<char> character_pool;
	for (char character : nString) {
		if (character_pool.find(character) != character_pool.end())
			return character;
		character_pool.insert(character);
	}

	return 0;
}
