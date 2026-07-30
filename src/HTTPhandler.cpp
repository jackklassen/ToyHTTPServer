//
// Created by Jack klassen on 2026-07-30.
//

#include "HTTPhandler.h"

std::string HTTPhandler::response(std::string body, int code, std::string content_type) {
    std::string response = "HTTP/1.1 200 OK \r\n" +
                           std::format("Content-Type: {}\r\n", content_type) +
                           std::format("Content-Length: {}\r\n", body.length()) +
                           "Connection: close\r\n" + "\r\n";

    //"HTTP/1.1 {status code} {reason} \r\n" //simply just give back 200 OK, code is code reason is human readable
    //"Content-Type: {content_type}\r\n" //by default just do text/plain
    //"Content-Length: {length of body} \r\n"
    //"Connection: close\r\n"
    //"\r\n"

    return response + body;


    //response is that + body
}
