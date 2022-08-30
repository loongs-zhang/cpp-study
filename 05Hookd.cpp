#include <iostream>
#include <unistd.h>
#include <thread>

int main() {
    std::thread::id threadId = std::this_thread::get_id();
    unsigned int tid = *(uint32_t *) &threadId;
    std::cout << "main current thread id: " << tid << std::endl;
    sleep(1);
    return 0;
}
