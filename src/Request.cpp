#include <string>
#include <iostream>
#include <string.h>
#include <unistd.h>
#include "Request.h"

using namespace std;




Request::Request(int fd){
        conFd = fd;
}

Request::~Request(){
}



void Request::parse(){
        int n = 0;
        char buf[2048];
        //do{ 
            memset(buf, 0, 2048);
            n = read(conFd, buf, 2048 );
            cout << buf << "|bufend|" << endl;
        //}while( /*48 == n */  n != -1 && n != 0); 
        
        
        string strRequest(buf);
        //cout << strRequest ;
        parseUri(strRequest);
            
        cout << endl << "-------------------" << n <<"--------------------" << endl;
        cout <<  "---------------------------------------" << endl;
        //close(conFd);
}

void Request:: parseUri(string strHttpReq){
    
    int index1 = 0, index2 = 0;
    index1 = strHttpReq.find(" ", 0);

    if(string::npos != index1){
        //cout << "index1 = " << index1 << "index2 = "<< index2 << endl;
        index2 = strHttpReq.find(" ", index1 + 1);
        if(string::npos != index2 && index2 > index1){
              
            uri = strHttpReq.substr(index1 + 1, index2 - index1 - 1);
            cout << "uri : " << uri << endl;
        }
    }
}


string Request::getUri(){
    return uri;
}















