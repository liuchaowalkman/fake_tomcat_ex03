
#include "HttpRequest.h"




void HttpRequest::setMethod(string method){
    this->httpRequestLine.method = method;
    return;
}

void HttpRequest::setUri(string uri){
    this->httpRequestLine.uri = uri;
    return;
}

void HttpRequest::setProtocol(string protocol){
    this->httpRequestLine.protocol = protocol;
    return;
}


string HttpRequest::getMethod(){
    return httpRequestLine.method;
}


string HttpRequest::getUri(){
    return httpRequestLine.uri;
}

string HttpRequest::getProtocol(){
    return httpRequestLine.protocol;
}


