#include"commonfunc.h"

int main(int argc, char const *argv[])
{
    char* getStr;
    getStr = malloc(BUFFER);
    if(fgets(getStr,BUFFER,stdin) ==0 || getStr[0] == '\n'){
        printf("Your Input cannot read.\n");
        return 1;
    }
    return 0;
}
