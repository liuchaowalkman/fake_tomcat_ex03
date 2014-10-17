
#ifndef FDREAD_H_
#define FDREAD_H_
#include <string>

using namespace std;

class FdRead{
    private:
        int input;
        bool disconnected;

    public:
        FdRead (int);
        string readAllString ();
        int readData(char*, int);
        bool IsConnectionOff();
};

#endif

