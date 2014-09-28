#ifndef RESPONSE_H_
#define RESPONSE_H_


#include "Request.h"

using namespace std;



class Response{

    #define BUFFER_SIZE 1024
    #define MAX_FILE_LEN 80 
    private:
        Request * pRequest;
        int conFd;

    public:
        Response(int);
        ~Response();
        void setRequest(Request* );
        int getWriter();
        void sendStaticResource();
};

#endif
