#include <iostream>
#include <thread>
#include <csignal>
#include <unistd.h>

void sigurg_handler(int signal) {
    std::cout << "signal:" << signal << " handled" << std::endl;
}

void print() {
    struct sigaction act;
    act.sa_mask = SIGURG;
    act.sa_handler = sigurg_handler;
    act.sa_flags = SA_RESTART;
    sigaction(SIGURG, &act, nullptr);
    //usleep无法根据SA_RESTART自行恢复
//    int result = usleep(1000000);
    char str[50];
    scanf("%s", str);
    std::cout << "result:" << str << std::endl;
}

int main() {
    std::thread t(print);
    usleep(100000);
    pthread_kill(t.native_handle(), SIGURG);
    t.join();
    return 0;
}
