//
// Created by Jack klassen on 2026-07-30.
//

#ifndef HTTPSERVER_HTTPHANDLER_H
#define HTTPSERVER_HTTPHANDLER_H
#include <string>
#include <format>

class HTTPhandler {

    private:
    //enum class StatusCode {
      //  OK = 200
   // };
    public:
    std::string response(std::string body, int code, std::string content_type);

};


#endif //HTTPSERVER_HTTPHANDLER_H
