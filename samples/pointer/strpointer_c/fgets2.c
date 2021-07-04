#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/**

 * fgetsで得た文字列をstrcspnで削除する
    →これなら改行文字を削除してくれる。(fgets1.cと比較せよ)
**/
#define BUFFER 65536

int main(int argc, char const *argv[])
{
    char* str;
    int stringlength;
    int pos;
    str = malloc(BUFFER);
    if(fgets(str,BUFFER,stdin) == 0 || str[0] == '\n'){
        printf("No Input!");
        return 1;
    }
    /**
    pos = strcspn(str,"\n");
    printf("RetPos %d\n",pos);
    **/
    str[strcspn(str,"\r\n")] = '\0';
    printf("Result str: %s\n",str);

    return 0;
}
