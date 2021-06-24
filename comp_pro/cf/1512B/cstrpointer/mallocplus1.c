#include<stdio.h>
#include<stdlib.h>

#define BUF 0

/*
    mallocで値を0にしたときはどうなるか
*/

int main(int argc, char const *argv[])
{
    char *a;
    a = (char *)malloc(BUF);
    scanf("%s",a);

    if(a == 0){
        printf("a は NULLです\n");
        return 1;
    }
    printf("%s\n",a);
    
    return 0;
}
