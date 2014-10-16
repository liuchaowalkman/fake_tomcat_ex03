
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Servlet.h"


using namespace std;

class PrimitiveServlet : public Servlet{
    public:

        PrimitiveServlet();
        ~PrimitiveServlet();
        
        virtual void init() ;
        virtual void service(Request*, Response*);
        virtual void destroy();
};


PrimitiveServlet::PrimitiveServlet(){
}

PrimitiveServlet::~PrimitiveServlet(){
}

void PrimitiveServlet::init(){
    cout << "init" << endl; 
}

void PrimitiveServlet::service(Request* request, Response* response){

    cout << "service" << endl; 
    int mWriter = response->getWriter();

    unsigned int n = -1;
    char wBuf[2048];
    memset(wBuf, 0, 2048);

    char const * sent = "Hello. Roses are red.";



    sent  =     "<html>"
                    "<head>"
                        "<title>the first html</title>"
                    "</head>"
                    "<body>"
                        "<br/>"
                        "hi, this is PrimitiveServlet!!!"
                    "</body>"
                "</html>";



    memcpy(wBuf, sent, strlen(sent) + 1);
    n = write(mWriter, wBuf, strlen(sent) + 1);
    if(n != strlen(sent) +1){
        cerr << "send less than giving" << endl;
    }
    return;
    
}

void PrimitiveServlet::destroy(){
    cout << "destroy" << endl; 
}
//PrimitiveServlet gps;
extern "C" void* getClassInstance(){

        cout << "in getClassInstance()" << endl;
        return new PrimitiveServlet;
    }
    
extern "C" void releaseClassInstance(void* mPrimitiveServlet){

        cout << "releaseClassInstance" << endl;
        delete (PrimitiveServlet*)mPrimitiveServlet;
    }

