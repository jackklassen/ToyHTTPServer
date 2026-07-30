//
// Created by Jack klassen on 2026-07-29.
//

#ifndef HTTPSERVER_SERVER_H
#define HTTPSERVER_SERVER_H
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>



class Server {
    private:
    int serverSocket;
    const int port = 9000;
    sockaddr_in serverAddress{};

    public:
    Server();

    void bindAndListen();

};


#endif //HTTPSERVER_SERVER_H
