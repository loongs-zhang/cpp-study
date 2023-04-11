#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <thread>

static bool run = true;

void yields() {
    std::cout << "coroutine yielded after signal_handler returned" << std::endl;
    run = false;
}

void signal_handler(int signum, siginfo_t *siginfo, void *p) {
    ucontext_t *context = static_cast<ucontext_t *>(p);
#if defined __linux__
    //x86_64 linux
    context->uc_mcontext.gregs[REG_RIP]= reinterpret_cast<__uint64_t>(yields);
#elif defined  __aarch64__
    //arm64 macos
    context->uc_mcontext->__ss.__pc = reinterpret_cast<__uint64_t>(yields);
#elif defined __x86_64__
    //x86_64 macos
    context->uc_mcontext->__ss.__rip = reinterpret_cast<__uint64_t>(yields);
#endif

    std::cout << "Received signal " << signum << " from process " << siginfo->si_pid << std::endl;
}

void thread_main() {
    // 定义 sigaction 结构体
    struct sigaction sa;
    sa.sa_sigaction = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO | SA_RESTART | SA_NODEFER;

    // 注册信号处理函数
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        std::cerr << "Failed to register handler for SIGINT" << std::endl;
        return;
    }

    while (run) {
        std::cout << "Waiting for signal..." << std::endl;
        sleep(1);
    }
}

int main() {
    std::thread t1(thread_main);
    sleep(1);
    pthread_kill(t1.native_handle(), SIGINT);
    t1.join();
    return 0;
}