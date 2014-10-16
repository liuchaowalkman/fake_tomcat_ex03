#include <stdio.h>
#include <sys/prctl.h>
#include <unistd.h>
#include "HttpConnector.h"
#include "Constants.h"


int main(){
    
    Constants::init();
    HttpConnector connector ;
    connector.start();
    pthread_exit(NULL);
//	return 0;
}

