//
// Created by Jack klassen on 2026-07-29.
//

#include "Server.h"
#include "HTTPhandler.h"
#include <sstream>
#include <string>

Server::Server() {
        serverSocket = socket(AF_INET, SOCK_STREAM, 0);
        serverAddress.sin_family = AF_INET;
        serverAddress.sin_port = htons(port);
        serverAddress.sin_addr.s_addr = INADDR_ANY;
}

void Server::bindAndListen() {

    bind(serverSocket, (struct sockaddr*)&serverAddress,
        sizeof(serverAddress));


    listen(serverSocket, 5);

    std::cout << "Hosting Server at http://localhost:" << port << "/" <<  std::endl;

    while (true) {
        int clientSocket = accept(serverSocket, nullptr,nullptr);
        char buffer[1024] = {0};
        int bytes_received =  recv(clientSocket, buffer,sizeof(buffer) - 1, 0);

        std::cout << "Client connected with request: " << std::endl << buffer << std::endl;

        HTTPhandler handler = HTTPhandler();



        HTTPHeader RequestHeader = HTTPhandler::getHTTPHeader(buffer);

        std::string body = "<h1>hello</h1> <p> I am an HTTP thingy </p>";


        std::string response = handler.response( body, RequestHeader, "text/html" );

        send(clientSocket,response.c_str(), response.length(), 0);
        close(clientSocket);
    }
    close(serverSocket);
}

