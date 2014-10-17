#ifndef HTTP_RESPONSE_H_
#define HTTP_RESPONSE_H_


#include "HttpRequest.h"
#include "FdWrite.h"

using namespace std;

class HttpRequest;

class HttpResponse{
#define BUFFER_SIZE  2048
    private:
        HttpRequest *pRequest;
        FdWrite fdWrite;

    public:
        HttpResponse(int);
        ~HttpResponse();
        
        void setRequest(HttpRequest*);
        void sendStaticResource();
        void write(string);
};



#endif
