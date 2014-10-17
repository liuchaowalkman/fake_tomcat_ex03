
#include <string.h>
#include <unistd.h>
#include "FdRead.h"
#include <iostream>

using namespace std;


FdRead::FdRead (int fd){
    this->input = fd;
}


string FdRead::readAllString(){

    string str("");
    int n = 0;
    char buf[2048];
    do{
        cout << "FdRead in do while before"  << endl;
        memset (buf, 0, 2048);
        n = read (input, buf, 2048);
        cout << "FdRead in do while, n = " << n << endl;
        if (n > 0){
	        str.append(buf);
	    }
    }while(n > 0 && 2048 == n);
    
    cout << "FdRead return" << endl;
    return str;
}

int FdRead::readData(char* buf, int maxSize){
    int n = 0;
    n = read(input, buf, maxSize);
    return n;
}
