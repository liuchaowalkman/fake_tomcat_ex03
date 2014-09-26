#ifndef REQUEST_H_
#define REQUEST_H_

#include <string>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;


class Request{
    private: int conFd;
             string uri;


    public: //Request();
            Request(int);
            ~Request();
            
            void parse();
            string getUri();

    private:void parseUri(string);
};


#endif


