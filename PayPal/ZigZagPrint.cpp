// Given a string and a number of lines k, print the string in zigzag
// form. In zigzag, characters are printed out diagonally from top left to
// bottom right until reaching the kth line, then back up to top right, 
// and so on.

// For example, given the sentence "thisisazigzag" and 
// k = 4, you should print.
/*
    t     a     g
     h   s z   a h
      i i   i z   i
       s     g
*/

#include <iostream>

std::string zigZagyfy(std::string sentence, int k);
std::string whiteSpaces(int n);

int main() {
    std::string sentence;
    int k;
    std::cin >> sentence;
    std::cin >> k;
    std::string answer = zigZagyfy(sentence, k);
    std::cout << answer << std::endl;
}

std::string zigZagyfy(std::string sentence, int k) {
    std::string answer = "";

    for (int i = 0; i < k; i++) {
        bool toggle = true;
        int downSpaces = (2 * (k - i - 1)) - 1;
        int upSpaces = (i * 2) - 1;
        answer += whiteSpaces(i);
        for (int j = i; j < sentence.size()-i; j++) {
            answer += sentence[j];
            if (toggle) {
                if (downSpaces <= 0) {
                    answer += whiteSpaces(upSpaces);
                    j += upSpaces;
                } else {
                    answer += whiteSpaces(downSpaces);
                    j += downSpaces;    
                }
            } else {
                if (upSpaces <= 0) {
                    answer += whiteSpaces(downSpaces);
                    j+= downSpaces;
                } else {
                    answer += whiteSpaces(upSpaces);
                    j += upSpaces;
                }
            }

            toggle = !toggle;
        }
        answer += "\n";
    }

    return answer;
}

std::string whiteSpaces(int n) {
    if (n <= 0) {
        return "";
    }
    std::string rtn = "";
    for (int i = 0; i < n; i++) 
        rtn += " ";
    return rtn;
}