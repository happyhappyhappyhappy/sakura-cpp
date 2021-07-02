#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define BUFFER 65536

bool serveFunc(char* sendStr){
    if(sendStr != NULL){
        printf("Get String : %s\n",sendStr);
        return true;
    }
    else{
        printf("Not Get String\n");
        return false;
    }
}

int main(int argc, char const *argv[])
{
    char* str;
    int strlength;

    str = malloc(BUFFER);
    if(fgets(str,BUFFER,stdin)==0 || str[0]=='\n'){
        printf("No Input.End.\n");
    }
    strlength = strcspn(str,"\r\n");
    printf("String Length : %d\n",strlength);
    str[strlength] = '\0';
    if(serveFunc(str)){
        printf("Send String OK!\n");
        return 0;
    }
    else{
        printf("Send String Fail!\n");
        return 1;
    }
}

