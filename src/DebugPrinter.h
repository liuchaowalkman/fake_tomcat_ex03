#ifndef DEBUG_PRINTER_H_
#define DEBUG_PRINTER_H_

#include <string>

using namespace std;

#define DEBUG_PRINTER_PRINT_LN(fmt, ...)  DebugPrinter::println(__FILE__, fmt, __VA_ARGS__)


class DebugPrinter{
    private:
        string strTag;

    public:

        static void println(const char*,const char*, ...);
        
        DebugPrinter(const char*);

        template <typename T>
        DebugPrinter& print(T val){
            cout << val;
            return *this;
        }

        DebugPrinter& print(){
            cout << endl;
            return *this;
        }

        

};


#endif
