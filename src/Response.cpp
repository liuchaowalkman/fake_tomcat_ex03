#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "Response.h"
#include "Request.h"
#include "HttpServer.h"

using namespace std;




Response::Response(int fd){
    conFd = fd;
}

Response::~Response(){
}

void Response::setRequest(Request* req){
    pRequest = req;
}

int Response::getWriter(){
    return conFd;
}


void Response::sendStaticResource(){
    char fileBuffer[BUFFER_SIZE]; 
    int fileFd = -1;
    int n = 0;
    string fileName(HttpServer::webRoot);

    fileName.append(pRequest->getUri());
    cout << fileName << endl;
    if(0 > (fileFd = open(fileName.c_str(), O_RDONLY)))
        cerr << "open file error, fileFd = " << fileFd << endl;
    
    do{
        memset(fileBuffer, 0, BUFFER_SIZE);
        n = read(fileFd, fileBuffer, BUFFER_SIZE);
        write(conFd, fileBuffer, n);
    }while( BUFFER_SIZE == n);
    cout << " write done, n = " << n << endl;

    
    
}

