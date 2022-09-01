#include <iostream>
#include <string>

int main() {
    std::string s("Hello World!\n");
    std::string s2("10");
    int num = std::stoi(s2);
    std::cout << "is empty:" << s.empty() << std::endl;
    std::cout << "size:" << s.size() << std::endl;
    std::cout << "equals:" << (s == s2) << std::endl;
    std::cout << std::to_string(num) << std::endl;
    std::cout << "input string, it ends with \\n" << std::endl;
    std::string line;
    std::getline(std::cin, line);
    std::cout << line << R"( ,"line" not ends with a \n)" << std::endl;
    return 0;
}
