


#ifndef HTTPCONNECTOR_H_
#define HTTPCONNECTOR_H_
#include "HttpConnector.h"
#include "HttpRequestLine.h"
#include "HttpRequest.h"
#include "HttpResponse.h"



class HttpProcessor{

        private:
            HttpConnector* connector;
            string strRequest;
            HttpRequestLine  httpRequestLine;
            HttpRequest *pRequest;
            HttpResponse *pResponse;

        public:
            HttpProcessor(HttpConnector*);
            void process(int );

            void readRequestLine();

};

#endif
