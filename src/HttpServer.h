/*************************************************************************
    > File Name: httpServer.cpp
    > Author: chaoliu    
    > Mail: chaoliu@marvell.com 
    > Created Time: Wed Sep 24 12:16:31 2014
 ************************************************************************/


#ifndef HTTPSERVER_H_
#define HTTPSERVER_H_

#include <string>
using namespace std;



class HttpServer{
    #define MAX_FILE_LEN 80

	public:  static string webRoot; 
             static bool webRootGot;
	private: static const string SHUTDOWN_COMMAND ;
			 bool shutdown ;
			 
	public:  HttpServer();
			 ~HttpServer();
			 
			 void await();
};

#endif

