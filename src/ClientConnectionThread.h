
#ifndef CLIENT_CONNECTION_THREAD_H_
#define CLIENT_CONNECTION_THREAD_H_

#include "Thread.h"
#include "HttpProcessor.h"

class ClientConnectionThread: public Thread{

    private:
        int conFd;
        HttpProcessor* processor;
    
    public:
        ClientConnectionThread(int fd, HttpProcessor* pro):
            conFd(fd),
            processor(pro){};
        virtual bool threadLoop(){
            processor->process(conFd); 
            return false;

        };

};


#endif
