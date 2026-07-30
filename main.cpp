#include <iostream>
#include "src/Server.h"
#include "src/HTTPhandler.h"

int main() {
    //implmentation goals in order
    //any request gets back valid http (done)
    //proper method gets valid http (in progress)
    //proper headers in full get valid http (todo)
    //proper headers in full get the http they want (todo)
    //proper requests gets a http that from a file (todo)
    //more than 1 client can access at a time. (todo)

    Server server = Server();

    server.bindAndListen();

    return 0;
}