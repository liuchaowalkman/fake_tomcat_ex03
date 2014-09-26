#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;


int main(){
    string str1("abcdef");


    int index = str1.find("h", 0);
    cout << index << endl;
    cout << ((int)string::npos) << endl;
    int aa = -1;
    cout <<  (-1 == string::npos) << endl;


    string *str2 = new  string("abcd");
    char cstr[100];
    const char *cstr2;
    str2->copy(cstr,100);
    cout << cstr << endl;
    
    cstr2 = str2->c_str();
    const void *p = cstr2;
    printf("*p=%p\n", p);
    delete str2;

    cout << cstr2 << endl;
}
