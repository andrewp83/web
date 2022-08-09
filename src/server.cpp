#include "server.hpp"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include <iostream>


namespace net {

static const int WORKERS_COUNT = 1;

Server::Server(int argc, char** argv, web::QueryHandler* handler):
handler(handler) {

}

int Server::run() {
    daemonize();
    create_workers();
    start_master_loop();
    return 0;
}

int Server::daemonize() {
    switch ( fork() )
    {
        case -1:
            return (-1);
        case 0:
            break;
        default:
            _exit(0);
    }

    if (setsid() == -1)
        return (-1);

    // if (!chdir("/"))
    //   exit(1);

    int fd = open("/dev/null", O_RDWR, 0);

    if (fd == -1)
        return (-1);

    (void)dup2(fd, STDIN_FILENO);
    (void)dup2(fd, STDOUT_FILENO);
    (void)dup2(fd, STDERR_FILENO);

    if (fd > 2)
        (void)close(fd);

    return (0);
}

void Server::start_master_loop() {
    // Создать серверный сокет и начать его слушать
    while (true) {
        sleep(10);
    }
}

void Server::start_worker_loop() {
    while (true) {
        sleep(10);
    }
}

void Server::create_workers() {
    for (int i = 0; i < WORKERS_COUNT; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            // ошибка вызова fork, надо обработать
            throw std::runtime_error("fork() call failed.");
        } else if (pid == 0) {
            start_worker_loop();
        } else {
            // ???
        }
    }
}

}