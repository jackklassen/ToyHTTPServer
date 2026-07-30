//
// Created by Jack klassen on 2026-07-30.
//

#include "HTTPhandler.h"

std::string HTTPhandler::response(std::string body, const int code, std::string content_type) {
    std::string response = "HTTP/1.1 " + std::to_string(code) + " " +  StatusCode[code] +  "\r\n" +
                           std::format("Content-Type: {}\r\n", content_type) +
                           std::format("Content-Length: {}\r\n", body.length()) +
                           "Connection: close\r\n" + "\r\n";

    return response + body;
}

HTTPHeader HTTPhandler::getHTTPHeader(char *raw_data) {

}


