
#include <string>
#include <iostream>
#include <dlfcn.h>
#include "ServletProcessor.h"
#include "Servlet.h"

using namespace std;



void ServletProcessor::process(HttpRequest* request, HttpResponse* response){
    string uri = request->getUri();

    string servletName = uri.substr(uri.find_last_of("/") + 1);
    cout << "servletName = " << servletName << endl;
    servletName.append(".so");
    servletName.insert(0, "./lib/");

    void* ServletHandle = NULL;
    
    
    if(NULL == (ServletHandle = dlopen(servletName.c_str(), RTLD_LAZY)))
        {cerr << "dlopen error  path:" << servletName.c_str() << "error:" << dlerror() << endl;  return ;}

    
    void* (*getClass)();

    getClass = (void* (*)()) dlsym(ServletHandle, "getClassInstance");
    if(getClass == NULL)
    {   cerr << "find getClassInstance() error " << endl;return ;}



    Servlet* servlet = (Servlet*)getClass();
    if(servlet == NULL)
    {   cout << "get servlet error " << endl;return ;}
 
    servlet->init();


    servlet->service(request, response);
    servlet->destroy();



    return ;
    
}
