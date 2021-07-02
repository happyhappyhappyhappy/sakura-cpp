#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define BUFFER 65536

bool serveFunc(char* sendStr){

    return true;
}

int main(int argc, char const *argv[])
{
    char* str;
    str = malloc(BUFFER);
    if(fgets(str,BUFFER,stdin)==0 || str[0]=='\n'){
        printf("No In");
    }
    return 0;
}

