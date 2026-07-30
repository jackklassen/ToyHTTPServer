#include <iostream>
#include "src/Server.h"
#include "src/HTTPhandler.h"
//go slow
//dead simple
//like this https://medium.com/@SavinuAththanyake/writing-your-own-http-server-in-python-1b9d9342f8b6
//and ever so slowly add more functionarly.
//as in first version is not picky, if a request is made at all return something
//then add better parsing.
//(headers don't need to be objects just use a map to hold the stuff you need (so string string , first is like method second is get etc)
//responeses for requesting
//actual control of endpoints
//maybe integration with file access
//finnally maybe threading.


int main() {
    //so in order
    //any request gets back valid http
    //proper method gets valid http
    //proper headers in full get valid http
    //proper headers in full get the http they want
    //proper requests gets a http that from a file

    //more than 1 client can access at a time.

    Server server = Server();

    server.bindAndListen();

    return 0;
}