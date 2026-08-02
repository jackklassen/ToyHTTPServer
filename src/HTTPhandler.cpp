//
// Created by Jack Klassen on 2026-07-30.
//

#include "HTTPhandler.h"

#include <iostream>
#include <ostream>
#include <sstream>

int HTTPhandler::DetermineCode(const HTTPHeader &request) {
    int code = 500; //By Default something went wrong.
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
    return code;
}

std::string HTTPhandler::response(std::string& body, const HTTPHeader& request, std::string content_type) {
    int code = 500;
    code = DetermineCode(request);

    if (code != 200) {
        body = "Error code: " + std::to_string(code) + " " + StatusCode[code];
    } else if (body == "404 Not Found") {
        //by no means the right way to do this.
        code = 404;
    }

    std::string response = "HTTP/1.1 " + std::to_string(code) + " " +  StatusCode[code] +  "\r\n" +
                           std::format("Content-Type: {}\r\n", content_type) +
                           std::format("Content-Length: {}\r\n", body.length()) +
                           "Connection: close\r\n" + "\r\n";
    return response + body;
}

std::vector<std::string> HTTPhandler::SplitAtSpace(std::string string_to_split) {
    std::stringstream string_stream(string_to_split);
    std::vector<std::string> string_split;
    std::string splitting_string;
    while (getline(string_stream, splitting_string, ' ')) {
        string_split.push_back(splitting_string);
    }
    return string_split;
}

HTTPHeader HTTPhandler::getHTTPHeader(char *raw_data) {
    HTTPHeader httpHeader;

    std::string request_string = std::string(raw_data);

    std::string first_part = request_string.substr(0, request_string.find("\r\n"));

    if (first_part.find("GET") != std::string::npos) {
        httpHeader.method = "GET";
    }

    std::vector<std::string> first_part_split = SplitAtSpace(first_part);
    httpHeader.uri = first_part_split[1];
    //this is not carefully grabbing just the accept but instead grabs only a chunk of chars
    //will require refinement for more complicated requests
    std::string accept_string = request_string.substr(request_string.find("Accept:"), 20);


    if (accept_string.find("text/html") != std::string::npos) {
        httpHeader.content_type = "text/html";
    }
    return httpHeader;

}