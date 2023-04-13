#include <iostream>
#include <csignal>
#include <unistd.h>
#include <thread>

static int count = 0;

void signal_handler(int signum) {
    std::cout << "Received signal " << signum << std::endl;
    count++;
    //解除信号屏蔽
    sigset_t mask;
    pthread_sigmask(SIG_BLOCK, NULL, &mask);
    sigdelset(&mask, SIGINT);
    pthread_sigmask(SIG_SETMASK, &mask, NULL);
    //模拟耗时操作
    while (count < 2) {
        std::cout << "signal handler Waiting for signal..." << std::endl;
        sleep(1);
    }
}

void thread_main() {
    // 定义 sigaction 结构体
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;

    // 注册信号处理函数
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        std::cerr << "Failed to register handler for SIGINT" << std::endl;
        return;
    }

    while (count < 2) {
        std::cout << "Waiting for signal..." << std::endl;
        sleep(1);
    }
    std::cout << "thread main finished!" << std::endl;
}

int main() {
    std::thread t1(thread_main);
    sleep(1);
    pthread_kill(t1.native_handle(), SIGINT);
    sleep(1);
    pthread_kill(t1.native_handle(), SIGINT);
    sleep(1);
    pthread_kill(t1.native_handle(), SIGINT);
    t1.join();
    return 0;
}