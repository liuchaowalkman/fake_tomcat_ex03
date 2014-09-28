
#include <string>
#include <iostream>
#include <dlfcn.h>
#include "ServletProcessor.h"
#include "Servlet.h"

using namespace std;



void ServletProcessor::process(Request* request, Response* response){
    string uri = request->getUri();

    string servletName = uri.substr(uri.find_last_of("/") + 1);
    cout << "servletName = " << servletName << endl;
    servletName.append(".so");
    servletName.insert(0, "./lib/");

    void* ServletHandle = NULL;
    
    
    if(NULL == (ServletHandle = dlopen(servletName.c_str(), RTLD_LAZY)))
        {cerr << "dlopen error " << endl;  return ;}

    
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