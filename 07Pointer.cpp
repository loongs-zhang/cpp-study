#include <iostream>

int main() {
    int val = 1024;
    //指针是对象，有自己的存储空间
    int *ptr = &val;
    std::cout << "val->" << *ptr << std::endl;
    return 0;
}
