
#ifndef FD_WRITE_H_
#define FD_WRITE_H_
#include <string>

using namespace std;

class FdWrite{
    private:
        int output;
    
    public:
        FdWrite(int);
        void write(char* , int );
        void write(string);
    
};

#endif
