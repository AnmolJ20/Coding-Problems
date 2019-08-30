// Given three 32-bit integers x, y, and b, return x if b
// is 1 and y if b is 0, using only mathematical or bit 
// operations. You can assume b can only be 1 or 0.

#include <iostream>

int returnValue(u_int32_t x, u_int32_t y, int b) {
    b = -b;
    return (x & b) | (y & ~b);
}

int main() {
    u_int32_t x, y;
    int b;
    std::cin >> x >> y >> b;
    std::cout << returnValue(x, y, b) << std::endl;
}