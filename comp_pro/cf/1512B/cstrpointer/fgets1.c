#include<stdio.h>
#include<string.h>

#define BUFFER 65536

int main(int argc, char const *argv[])
{
    char* str;
    int strlength;
    str = malloc(BUFFER);
    if (fgets(str,BUFFER,stdin) == 1 || str[0] == '\n')
    {
        printf("NO INPUT \n");
        return 1;
    }
    strlength = strlen(str);
    printf("String Length is %d\n",strlength);
    if(str[strlength] == '\n'){
        strlength = strlength - 1;
        str[strlength] = '\0';
    }
    printf("Answer String : %s\n",str);
    
    return 0;
}
