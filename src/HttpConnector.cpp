
#include <iostream>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <string.h>

#include "HttpRequest.h"
#include "HttpResponse.h"
#include "ServletProcessor.h"
#include "StaticResourceProcessor.h"

#include "HttpConnector.h"
#include "Thread.h"
#include "HttpProcessor.h"
#include "ClientConnectionThread.h"





HttpConnector::HttpConnector(const char* cScheme ) : scheme(cScheme), stopped(false){
}

HttpConnector::HttpConnector(string str ) : scheme(str), stopped(false){
}

HttpConnector::~HttpConnector(){
}

string HttpConnector::getScheme(){
    return scheme;
}


bool HttpConnector::threadLoop(){


    struct sockaddr_in  serverAddr;
    int listenFd ;
    int const port = 8080;
    int const maxConCount = 1;
    
    HttpProcessor processor(this);

    cout << "Httpconector::run.  " << endl;
    listenFd =  socket(AF_INET, SOCK_STREAM, 0);
    bzero(&serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    //serverAddr.sin_addr.s_addr = inet_addr("0.0.0.0");
    serverAddr.sin_port = htons(port);

    int recode = bind(listenFd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(listenFd, maxConCount);

        cout << "Httpconector::run2.  " << endl;
    while(!stopped){
        struct sockaddr_in clientAddr;
        int conFd;
        socklen_t clientLen = sizeof(clientAddr);

        conFd = accept(listenFd, (struct sockaddr*)&clientAddr, &clientLen);
        
        cout << "Httpconector::accept.    conFd = " << conFd << endl;

        ClientConnectionThread* ct = new ClientConnectionThread(conFd, &processor); 
        //processor.process(conFd);
        ct->start();

        //close(conFd);

            
        
    }
        
}



