//
// Created by Jack Klassen on 2026-07-29.
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
        std::string body;

        if (RequestHeader.uri == "/") {
            body = getFile("/index");
        } else {
            body = getFile(RequestHeader.uri);
        }

        if (body == "") {
            body = "404 Not Found";
        }

        std::string response = handler.response( body, RequestHeader, "text/html" );

        send(clientSocket,response.c_str(), response.length(), 0);
        close(clientSocket);
    }
    close(serverSocket);
}

std::string Server::getFile(std::string filename) {

    std::ifstream file_html("../assets"+filename + ".html");


    std::ifstream file_txt("../assets"+filename + ".txt");

    std::string return_string;
    std::ostringstream string_stream;

    if (file_html.is_open()) {
        string_stream << file_html.rdbuf();
        return_string = string_stream.str();
        std::cout << return_string << std::endl; ///the only real issue is handling pathing.
    } else if (file_txt.is_open()) {
        string_stream << file_txt.rdbuf();
        return_string = string_stream.str();
    } else {
        return_string = "";
    }

    return return_string;
}
