

#include "StaticResourceProcessor.h"




void StaticResourceProcessor::process(HttpRequest* request, HttpResponse* response){
    response->sendStaticResource(); 
    return;
}
