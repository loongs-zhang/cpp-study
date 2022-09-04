#include <iostream>

std::tuple<int, int> tuple() {
    return std::tuple<int, int>(0, 1);
}

int main() {
    std::tuple<int, int> result = tuple();
    std::cout << "index0-> " << std::get<0>(result) << std::endl;
    std::cout << "index1-> " << std::get<1>(result) << std::endl;
    return 0;
}
