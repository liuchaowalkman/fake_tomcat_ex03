
#ifndef HTTP_REQUEST_H_
#define HTTP_REQUEST_H_

#include "HttpRequestLine.h"
#include "HttpProcessor.h"

using namespace std;

class HttpRequest{
    private:
        HttpRequestLine httpRequestLine;
    
    friend class HttpProcessor;    

    private:
        void setMethod(string);
        void setUri(string);
        void setProtocol(string);

    public:
        string getMethod();
        string getUri();
        string getProtocol();
};

#endif

