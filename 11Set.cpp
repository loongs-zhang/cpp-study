#include <iostream>
#include <set>

int main() {
    std::set<int> set{1};
    std::cout << "is empty:" << set.empty() << std::endl;
    set.insert(2);
    set.insert(2);
    std::cout << "size:" << set.size() << std::endl;
    std::cout << "max size:" << set.max_size() << std::endl;
    return 0;
}
