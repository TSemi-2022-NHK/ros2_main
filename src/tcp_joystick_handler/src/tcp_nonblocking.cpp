//
// Created by ryuzo on 2022/05/03.
//

#include "tcp_joystick_handler/tcp_nonblocking.hpp"

tcp::tcp(const int port) {
    orgSock = socket(AF_INET, SOCK_STREAM, 0);
    memset(&origin_addr, 0, sizeof(struct sockaddr_in));
    origin_addr.sin_family = AF_INET;
    origin_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    origin_addr.sin_port = htons(port);
}

int tcp::receive_setup() {
    bind(orgSock, (struct sockaddr *)&origin_addr, sizeof(origin_addr));
    if (fcntl(orgSock, F_SETFL, O_NONBLOCK) < 0) {    //Set socket to non-blocking mode.
        perror("Setting");
    }
    listen(orgSock, 1);
    return 0;
}

std::basic_string<char> tcp::recieveLines() {
    ssize_t i, rc;
    char c;
    std::string lineString;
    lineString = "";
    for (i = 1; i < MAXLINE; ++i) {
        rc = read(dstSock, &c, 1);
        if (rc < 0) {
            if (errno !=
                (EAGAIN | EWOULDBLOCK)) {   // these errors occur when nothing can be read in non-blocking mode.
                perror("read");
            }
            break;
        }
        if (rc == 1){
            lineString += c;
            if (c == '\n'){
                break;
            }
        } else if (rc == 0){
            if (i == 1){
                return const_cast<char *>(std::string("").c_str());
            } else {
                break;
            }
        } else {
            close(dstSock);
        }
    }
    return lineString;
}

const char *tcp::connect() {
    socklen_t len = sizeof(destination_addr);
    dstSock = accept4(orgSock, (struct sockaddr *)&destination_addr, &len, SOCK_NONBLOCK | SOCK_CLOEXEC);
    if (dstSock == -1){
        if (errno !=
            (EAGAIN | EWOULDBLOCK)) {   // these errors occur when nothing can be read in non-blocking mode.
            perror("connect");
            return "-1";
        }
        return "0";
    }
    return inet_ntop(AF_INET, &destination_addr.sin_addr, buffer, sizeof(buffer));
}

tcp::~tcp() {
    close(orgSock);
}
