/************************************************************************
    > File Name: httpServer.cpp
    > Author: chaoliu    
    > Mail: chaoliu@marvell.com 
    > Created Time: Wed Sep 24 12:16:31 2014
 ************************************************************************/

#include <iostream>
#include <string>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <string.h>

#include "HttpServer.h"
#include "Request.h"
#include "Response.h"
#include "ServletProcessor.h"

using namespace std;




const string HttpServer::SHUTDOWN_COMMAND("/SHUTDOWN");
bool HttpServer::webRootGot = false;

string HttpServer::webRoot("./");

HttpServer::HttpServer():shutdown(false){
    if(!webRootGot){
        char path[MAX_FILE_LEN];
        getcwd(path,MAX_FILE_LEN);

        //cout << "web_root:" << path << endl;
        webRoot = path;
        webRoot.append("/webroot");
        cout << "web_root:" << webRoot << endl;

    }
}


HttpServer::~HttpServer(){

}

void HttpServer::await(){

    struct sockaddr_in  serverAddr;
    int listenFd ;
    int const port = 8080;
    int const maxConCount = 1;

    listenFd =  socket(AF_INET, SOCK_STREAM, 0);
    bzero(&serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    //serverAddr.sin_addr.s_addr = inet_addr("0.0.0.0");
    serverAddr.sin_port = htons(port);

    int recode = bind(listenFd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    

    listen(listenFd, maxConCount);
    while(!shutdown){
        struct sockaddr_in clientAddr;
        int conFd;
        socklen_t clientLen = sizeof(clientAddr);

        conFd = accept(listenFd, (struct sockaddr*)&clientAddr, &clientLen);
        
        cout << "conFd = " << conFd << endl;

        Request mRequest(conFd);
        mRequest.parse();
        
        Response mResponse(conFd);
        mResponse.setRequest(&mRequest);

        if(0 == mRequest.getUri().find("/servlet/", 0)){
            cout << "===========/servlet/===============" << endl;
            ServletProcessor processor;
            processor.process(&mRequest, &mResponse);

        }else{
            cout << "===========static resource===============" << endl;
            mResponse.sendStaticResource();
        }


        close(conFd);

        shutdown = (0 == mRequest.getUri().compare(SHUTDOWN_COMMAND));
            
        
/*
        int n = 0;
        char buf[2048];
        do{
            memset(buf, 0, 2048);
            n = read(conFd, buf, 48 );
            cout << buf ;
            //cout << endl << "n = " << n << endl;
        }while(n != -1 && n != 0);
        cout << endl << "---------------------------------------" << endl;
        close(conFd);
*/
    }
        
}



