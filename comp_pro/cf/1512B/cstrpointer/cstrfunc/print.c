#include"commonfunc.h"

bool serveStrOK(char* getStr){
    bool result=false;
    if(getStr != NULL){
        printf("Get String : %s .\n",getStr);
        result = true;
    }
    else{
        print("Not Get String NG. \n");
    }
    return result;
}