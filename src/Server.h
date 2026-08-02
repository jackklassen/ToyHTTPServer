//
// Created by Jack Klassen on 2026-07-29.
//

#ifndef HTTPSERVER_SERVER_H
#define HTTPSERVER_SERVER_H
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fstream>

#include "HTTPhandler.h"


class Server {
    private:
    int serverSocket;
    const int port = 9000;
    sockaddr_in serverAddress{};

    public:
    Server();

    void handleClient(int clientSocket);

    void bindAndListen();



    /**
     *
     * @param filename
     * @return returns file data as string if file exists as .html or .txt if it exists otherwise returns empty string
     */
    std::string getFile(std::string filename);

};


#endif //HTTPSERVER_SERVER_H
