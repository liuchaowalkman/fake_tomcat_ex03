

#include "StaticResourceProcessor.h"




void StaticResourceProcessor::process(Request* request, Response* response){
    response->sendStaticResource(); 
    return;
}
