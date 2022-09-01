#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> map;
    std::cout << "is empty:" << map.empty() << std::endl;
    map["2"] = 2;
    map["3"] = 3;
    std::cout << "size:" << map.size() << std::endl;
    std::cout << "max size:" << map.max_size() << std::endl;
    int val = map.find("3")->second;
    std::cout << "value:" << val << std::endl;
    return 0;
}
