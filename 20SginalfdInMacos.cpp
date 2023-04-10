#include <iostream>
#include <sys/event.h>
#include <csignal>
#include <unistd.h>

#define MAX_EVENTS 10

int main() {
    //屏蔽默认处理
    sigsetmask(SIGINT);

    // 创建kqueue对象
    int kq = kqueue();
    if (kq == -1) {
        std::cerr << "Error creating kqueue: " << strerror(errno) << std::endl;
        return 1;
    }

    // 监听SIGINT信号
    struct kevent sigintEvent;
    EV_SET(&sigintEvent, SIGINT, EVFILT_SIGNAL, EV_ADD, 0, 0, NULL);
    int result = kevent(kq, &sigintEvent, 1, NULL, 0, NULL);
    if (result == -1) {
        std::cerr << "Error adding signal event to kqueue: " << strerror(errno) << std::endl;
        close(kq);
        return 1;
    }

    // 等待事件发生
    struct kevent eventList[MAX_EVENTS];
    while (true) {
        int numEvents = kevent(kq, NULL, 0, eventList, MAX_EVENTS, NULL);
        if (numEvents == -1) {
            std::cerr << "Error waiting for events on kqueue: " << strerror(errno) << std::endl;
            close(kq);
            return 1;
        }

        // 处理所有事件
        for (int i = 0; i < numEvents; ++i) {
            int signalNum = eventList[i].ident;

            // 处理收到的信号
            if (signalNum == SIGINT) {
                std::cout << "\nReceived SIGINT signal!" << std::endl;
                close(kq);
                return 0;
            }
        }
    }
}