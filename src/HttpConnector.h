
#ifndef HTTPCONNETOR_H_
#define HTTPCONNETOR_H_
#include <string>

#include "Thread.h"


using namespace std;

class HttpConnector : public Thread{
    private:
        bool stopped;
        string scheme;

    public:
        HttpConnector(string);
        HttpConnector( const char* cScheme = "http");
        virtual ~HttpConnector();

        virtual bool threadLoop();
        string getScheme();

};



#endif

