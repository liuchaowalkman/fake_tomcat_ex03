
#include <unistd.h>
#include <string>
#include <iostream>
#include <assert.h>
#include "Constants.h"


Constants* Constants::self = NULL;
string Constants::webRoot(".");           


void Constants::init(){
	if(!self){
        self = new Constants();
	}
	else{
		cout << "muti init class Constants" << endl;
	//assert(0);
	}
	return;
}   

void Constants::destroy(){
	if(self) delete self;
	return;
}

Constants::Constants(){
	char path[MAX_FILE_LEN];
	getcwd(path,MAX_FILE_LEN);

	//cout << "web_root:" << path << endl;
    webRoot = path;
    webRoot.append("/webroot");
	cout << "web_root:" << webRoot << endl;

}



