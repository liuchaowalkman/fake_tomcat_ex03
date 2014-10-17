#ifndef SERVLET_H_
#define SERVLET_H_

#include "HttpRequest.h"
#include "HttpResponse.h"

class Servlet{

    public:
        Servlet();
        ~Servlet();
        virtual void init() = 0;
        virtual void service(HttpRequest*, HttpResponse*) = 0;
        virtual void destroy() = 0;
        
};



#endif

