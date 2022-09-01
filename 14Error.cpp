#include <iostream>
#include <stdexcept>

int main() {
    try {
        //危险操作，未catch会直接终止程序
        throw std::runtime_error("a runtime_error");
    } catch (std::runtime_error e) {
        std::cout << e.what() << std::endl;
    }
    try {
        //危险操作，未catch会直接终止程序
        throw std::invalid_argument("invalid arguments");
    } catch (std::invalid_argument e) {
        std::cout << e.what() << std::endl;
    }
    //使用RAII来解决没有finally的问题
    return 0;
}
