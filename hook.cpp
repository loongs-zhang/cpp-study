#include <iostream>
#include <unistd.h>
#include <thread>

unsigned int sleep(unsigned int s) {
    std::thread::id threadId = std::this_thread::get_id();
    unsigned int tid = *(uint32_t *) &threadId;
    std::cout << "hooked current thread id: " << tid << std::endl;
    std::cout << "simulate sleep for "<<s<<"s" << std::endl;
    return 0;
}
