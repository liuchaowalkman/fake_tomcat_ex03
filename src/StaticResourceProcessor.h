#ifndef STATICRESOURCEPROCESSOR_H_
#define STATICRESOURCEPROCESSOR_H_

#include "HttpRequest.h"
#include "HttpResponse.h"


class StaticResourceProcessor{
    public:
        void process(HttpRequest*, HttpResponse*);
};

#endif

