#include <iostream>
#include <vector>

int main() {
    std::vector<int> vector{1};
    std::cout << "is empty:" << vector.empty() << std::endl;
    vector.push_back(2);
    std::cout << "capacity:" << vector.capacity() << std::endl;
    vector.push_back(2);
    std::cout << "size:" << vector.size() << std::endl;
    std::cout << "capacity:" << vector.capacity() << std::endl;
    std::cout << "max size:" << vector.max_size() << std::endl;
    return 0;
}
