#ifndef  SERVLETPROCESSOR_H_ 
#define  SERVLETPROCESSOR_H_ 


#include "HttpRequest.h"
#include "HttpResponse.h"


class ServletProcessor{
    public:
        virtual void process(HttpRequest*, HttpResponse*);
};

#endif

