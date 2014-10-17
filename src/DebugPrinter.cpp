

#include <stdio.h>
#include <stdarg.h> 
#include <iostream>
#include "DebugPrinter.h"

using namespace std;


void DebugPrinter::println(const char* tag, const char* fmt,  ...){
    #define LOG_BUF_SIZE 1024
    va_list ap;
    char buf[LOG_BUF_SIZE];

    va_start(ap, fmt);
    vsnprintf(buf, LOG_BUF_SIZE, fmt, ap);
    va_end(ap);
    
    cout << tag << ":\t" << buf << endl;

}


DebugPrinter::DebugPrinter(const char* tag): strTag(tag){
}


