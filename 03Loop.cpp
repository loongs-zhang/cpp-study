#include <iostream>

int main() {
    for (int i = 0; i < 3; ++i) {
        std::cout << "a thousand miles begins with a single step" << std::endl;
    }
    int sum = 0, value = 0;
    //直到流的输入遇到错误为止
    while (std::cin >> value) {
        sum += value;
    }
    std::cout << "sum->" << sum << std::endl;
    return 0;
}
