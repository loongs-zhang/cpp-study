#include <iostream>
#include <stdexcept>

int add(int x = 0, int y = 1) {
    return x + y;
}

int main() {
    std::cout << add() << std::endl;
    std::cout << add(2) << std::endl;
    return 0;
}
