//
// Created by Jack klassen on 2026-07-30.
//

#ifndef HTTPSERVER_HTTPHANDLER_H
#define HTTPSERVER_HTTPHANDLER_H
#include <string>
#include <format>
#include <map>

struct HTTPHeader {
    std::string method = "";
    int code = 400;
    std::string content_type = "text/plain";
    std::string uri = "";
};

class HTTPhandler {

    private:
    std::map<int, std::string> StatusCode {
          {200, "OK"},
        {400, "Bad Request"},
        {500, "Internal Server Error"},
        {599, "Request Header Missing"}
    };
    public:


    /**
     * takes in body, code and content type and spits out a valid HTTP response
     *
     * @param body
     * @param request
     * @param code
     * @param content_type
     * @return assembled HTTP respose
     */
    std::string response(const std::string& body = "I need a body", const HTTPHeader& request = {"BAD", 599,"",""}, std::string content_type = "text/plain");

    /**
     * function to take raw client data in and
     * spit out and object with header data that I can easily use.
     * @param raw_data
     * @return
     */
    static HTTPHeader getHTTPHeader(char* raw_data);



};





#endif //HTTPSERVER_HTTPHANDLER_H
