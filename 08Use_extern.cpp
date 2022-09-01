#include <iostream>

#include "08Extern.h"

extern int b1;

extern int sum(int x1, int x2);

int main() {
    std::cout << b1 << std::endl;
    std::cout << sum(1, 2) << std::endl;
    return 0;
}
