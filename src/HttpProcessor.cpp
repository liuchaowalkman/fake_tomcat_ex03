
#include <unistd.h>
#include "FdRead.h"
#include "HttpProcessor.h"
#include <iostream>
#include "StaticResourceProcessor.h"
#include "ServletProcessor.h"
#include "DebugPrinter.h"

using namespace std;


HttpProcessor::HttpProcessor(HttpConnector* connector): pResponse(NULL), pRequest(NULL){
    this->connector = connector;
}


void HttpProcessor::process(int fd){
    
    DebugPrinter dp(__FILE__);
    FdRead fdRead(fd);
    while(!fdRead.IsConnectionOff()){
        
        strRequest = fdRead.readAllString();
        readRequestLine();

        cout << "method:" << httpRequestLine.method << endl;
        cout << "uri:" << httpRequestLine.uri << endl;
        cout << "protocol:" << httpRequestLine.protocol << endl;
    
        pRequest = new HttpRequest();
        pResponse = new HttpResponse(fd);
        pRequest->setMethod(httpRequestLine.method);
        pRequest->setUri(httpRequestLine.uri);
        pRequest->setProtocol(httpRequestLine.protocol);
    
        pResponse->setRequest(pRequest);
        if(0 == pRequest->getUri().find("/servlet/", 0)){
            cout << "===========/servlet/===============" << endl;
            ServletProcessor processor;
            processor.process(pRequest, pResponse);

        }else{
            cout << "===========static resource===============" << endl;
            // mResponse.sendStaticResource();
            StaticResourceProcessor processor;
            processor.process(pRequest, pResponse);
        }
    }

    dp.print("---------------------------------").print().
       print("connection ").print(fd).print(" off").print().
       print("---------------------------------").print();
    
    close(fd);
    return;

}

void HttpProcessor::readRequestLine(){
    int pos = 0;
    string str(strRequest);
    //skip \r and \n
    while(pos < str.size() &&
        ('\r' == str[pos] ||
         '\n' == str[pos])){
        str.erase(0, 1);
    };

    //get the method name
    while(pos < str.size() && ' ' != str[pos]){
        pos++;
    };

    httpRequestLine.method = str.substr(0, pos);
    
    //get the URI
    str.erase(0, pos + 1);
    pos = 0;
    while(pos < str.size() && ' ' != str[pos]){
        pos++;
    };

    httpRequestLine.uri = str.substr(0, pos);

    //get the protocol 
    str.erase(0, pos + 1);
    pos = 0;
    while(pos < str.size() && '\n' != str[pos] /* skip \n*/){
        pos++;
    };

    httpRequestLine.protocol = str.substr(0, pos);

    


}

    


