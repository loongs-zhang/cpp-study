#include <iostream>

int add(int x = 0, int y = 1) {
    return x + y;
}

int main() {
    std::cout << add() << std::endl;
    //只能省略尾部的实参
    std::cout << add(2) << std::endl;
    return 0;
}
