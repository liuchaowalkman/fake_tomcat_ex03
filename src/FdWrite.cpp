
#include <string>
#include  <unistd.h>
#include "FdWrite.h"
#include <iostream>



FdWrite::FdWrite(int fd){
    this->output = fd;
}

void FdWrite::write(string outStr){
    int pos = 0;
    int n = 0;
    int size = outStr.size();
    do{
            //add :: to link the linux C lib
            n = ::write(output, outStr.substr(pos, size - pos).c_str(), size);
        
        if(n > 0)   pos += n; 
        cout << "------n = " << n << ", pos = "<< pos << ", size = " << size << endl;
    }while(pos <  size);

}

void FdWrite::write(char* outBuf, int maxSize){
    int pos = 0;
    int n = 0;
    
    do{
        n = ::write(output, outBuf, maxSize);
        if(n > 0) pos += n;
    }while(pos < maxSize);
}
