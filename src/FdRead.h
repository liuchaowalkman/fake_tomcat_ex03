
#ifndef FDREAD_H_
#define FDREAD_H_
#include <string>

using namespace std;

class FdRead{
    private:
        int input;

    public:
        FdRead (int);
        string readAllString ();
        int readData(char*, int);
};

#endif

