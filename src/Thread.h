
#ifndef THREAD_H_
#define THREAD_H_

#include <pthread.h>
#include <sys/types.h> 

class Thread{
    private:
        bool mRunning;
        bool mExitPending;

        pthread_t mThread;

    public:
        Thread();
        ~Thread();
        virtual int run();
        virtual bool threadLoop() = 0;
        virtual int threadPrepare();
        
        void setThreadName(char*);
        void start();

    private:
        static void* _threadLoop(void *);
};


#endif
