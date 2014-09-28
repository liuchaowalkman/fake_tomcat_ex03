#ifndef SERVLET_H_
#define SERVLET_H_

#include "Request.h"
#include "Response.h"

class Servlet{

    public:
        Servlet();
        ~Servlet();
        virtual void init() = 0;
        virtual void service(Request*, Response*) = 0;
        virtual void destroy() = 0;
        
};



#endif

