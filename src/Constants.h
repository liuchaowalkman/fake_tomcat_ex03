
#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include <string>

using namespace std;

 class Constants{
    
    #define MAX_FILE_LEN 80
    public:
        static  string webRoot;

    //private:
        static Constants* self;

    public:

        static void init();


        static void destroy();



    private:
        Constants();

};








#endif

