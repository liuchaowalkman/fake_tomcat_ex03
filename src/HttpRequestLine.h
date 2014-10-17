

#ifndef HTTPREQUESTLINE_H_
#define HTTPREQUESTLINE_H_

#include <string>
using namespace std;

class HttpRequestLine{
    public:
        string method;
        string uri;
        string protocol;
};


#endif
