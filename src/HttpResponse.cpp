#include <iostream>
#include <string>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "Constants.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "FdWrite.h"
#include "FdRead.h"

using namespace std;

HttpResponse::HttpResponse(int fd): fdWrite(fd){
}

HttpResponse::~HttpResponse(){
}

void HttpResponse::setRequest(HttpRequest* req){
    pRequest = req;
}

void HttpResponse::write(string str){
    fdWrite.write(str);
}   


void HttpResponse::sendStaticResource(){
    char fileBuffer[2048]; 
    int fileFd = -1;
    int n = 0;
    string fileName(Constants::webRoot);

    fileName.append(pRequest->getUri());
    cout << fileName << endl;
    if(0 > (fileFd = open(fileName.c_str(), O_RDONLY))){
        cerr << "open file error, fileFd = " << fileFd << endl;
        return;
    }
    
    FdRead fileRead(fileFd);

    

    do{
        n = fileRead.readData(fileBuffer, 2048);
        fdWrite.write(fileBuffer, n);
    }while( 2048 == n);
    
    

    /*do{
        memset(fileBuffer, 0, BUFFER_SIZE);
        n = read(fileFd, fileBuffer, BUFFER_SIZE);
        write(conFd, fileBuffer, n);
    }while( BUFFER_SIZE == n);*/
    cout << " write done, n = " << n << endl;

    
    
}

