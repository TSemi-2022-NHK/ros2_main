//
// Created by ryuzo on 2022/05/03.
//

#ifndef BUILD_TCP_NONBLOCKING_HPP
#define BUILD_TCP_NONBLOCKING_HPP

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <fcntl.h>

#define BUFFER_SIZE 256
#define MAXLINE 4096

class tcp {
    int orgSock{};
    int dstSock{};
    struct sockaddr_in origin_addr{};
    struct sockaddr_in destination_addr{};
    int numrcv{};
    char buffer[BUFFER_SIZE]{};

public:
    explicit tcp(int port);

    int receive_setup();

    std::basic_string<char> recieveLines();

    const char *connect();

    ~tcp();
};

#endif //BUILD_TCP_NONBLOCKING_HPP
