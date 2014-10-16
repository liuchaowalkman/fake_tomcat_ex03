
#include <sys/prctl.h>
#include <stdio.h>
#include "Thread.h"



Thread::Thread() : 
    mRunning(false), 
    mExitPending(false), 
    mThread(-1) {

}

Thread::~Thread(){ 
}


void Thread::start(){
    this->run();
}


int Thread::run(){
    if(mRunning){
        return -2;
    }

    mRunning = true;

    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);


    mExitPending = false;
    pthread_create(&mThread, &attr, _threadLoop, this);


}

void Thread::setThreadName(char* threadName){
    if(threadName){
        prctl(PR_SET_NAME, threadName);
    }
}
int Thread::threadPrepare(){
    return 0;
}

void* Thread::_threadLoop(void* user){
   
    Thread* const self = static_cast<Thread*>(user);
    bool result ;
    

    result = (0 == self->threadPrepare());
    while(result){
        result = self->threadLoop();
    };

}




