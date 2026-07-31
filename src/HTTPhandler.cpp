//
// Created by Jack klassen on 2026-07-30.
//

#include "HTTPhandler.h"

#include <iostream>
#include <ostream>

std::string HTTPhandler::response(const std::string& body, const HTTPHeader& request, std::string content_type) {
    int code = 500;


    //as this bloats it should be excised into another function.
    if (request.method == "BAD") {
        code = 500; //server error
    }else {

        if (request.method == "GET") {
            if (request.content_type == "text/html") {
                code = 200;
            }
        } else {
            code = 400; //client bad request
        }
    }


    std::string response = "HTTP/1.1 " + std::to_string(code) + " " +  StatusCode[code] +  "\r\n" +
                           std::format("Content-Type: {}\r\n", content_type) +
                           std::format("Content-Length: {}\r\n", body.length()) +
                           "Connection: close\r\n" + "\r\n";
    std::cout << response;
    //its not properly sending right respose given request also when errors happen it should respond with error message

    return response + body;
}

HTTPHeader HTTPhandler::getHTTPHeader(char *raw_data) {
    HTTPHeader httpHeader;

    std::string request_string = std::string(raw_data);

    std::string first_part = request_string.substr(0, request_string.find("\r\n"));

    if (first_part.find("GET") != std::string::npos) {
        httpHeader.method = "GET";
    }

    //this is not carefully grabbing just the accept but instead grabs only a chunk of chars
    //will require refinement for more complicated requests
    std::string accept_string = request_string.substr(request_string.find("Accept:"), 20);


    if (accept_string.find("text/html") != std::string::npos) {
        httpHeader.content_type = "text/html";
    }


    //GET /test HTTP/1.1 URI is in the middle. so URI might be / as start space or http as end.




    return httpHeader;

}