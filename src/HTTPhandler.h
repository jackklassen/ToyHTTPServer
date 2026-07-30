//
// Created by Jack klassen on 2026-07-30.
//

#ifndef HTTPSERVER_HTTPHANDLER_H
#define HTTPSERVER_HTTPHANDLER_H
#include <string>
#include <format>
#include <map>

class HTTPHeader {
public:
    std::string method;
    int code;
    std::string uri;
};

class HTTPhandler {

    private:
    std::map<int, std::string> StatusCode {
          {200, "OK"}
    };
    public:


    /**
     * takes in body, code and content type and spits out a valid HTTP response
     *
     * @param body
     * @param code
     * @param content_type
     * @return assembled HTTP respose
     */
    std::string response(std::string body, int code = 200, std::string content_type = "text/plain");

    /**
     * function to take raw client data in and
     * spit out and object with header data that I can easily use.
     * @param raw_data
     * @return
     */
    HTTPHeader getHTTPHeader(char* raw_data);
};





#endif //HTTPSERVER_HTTPHANDLER_H
