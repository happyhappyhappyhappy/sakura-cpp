#include"commonfunc.h"

int main(int argc, char const *argv[])
{
    char* getStr;
    int strlength;
    bool resultFlag=false;
    getStr = malloc(BUFFER);
    
    if(fgets(getStr,BUFFER,stdin) ==0 || getStr[0] == '\n'){
        printf("Your Input cannot read.\n");
        return 1;
    }
    else{
        strlength = strcspn(getStr,RC);
        getStr[strlength] = '\0';
        resultFlag=serveStrOK(getStr);
        if(resultFlag){
            printf("Send Other File Function OK!\n");
            return 0;
        }
        else{
            printf("Failed to send other file function.\n");
        }
    }
    return 0;
}
