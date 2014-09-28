#ifndef  SERVLETPROCESSOR_H_ 
#define  SERVLETPROCESSOR_H_ 


#include "Request.h"
#include "Response.h"


class ServletProcessor{
    public:
        virtual void process(Request*, Response*);
};

#endif

