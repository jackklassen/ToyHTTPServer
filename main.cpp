#include <iostream>
#include "src/Server.h"
#include "src/HTTPhandler.h"

int main() {
    //implementation goals in order
    //any request gets back valid HTTP (done)
    //proper method gets valid HTTP (done)
    //proper headers in full get valid HTTP (done)
    //proper requests gets a HTTP that from a file (in progress)
    //more than 1 client can access at a time. (todo)

    Server server = Server();

    server.bindAndListen();

    return 0;
}