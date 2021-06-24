#include<stdio.h>
#include<stdlib.h>
/*
    初期化で何も与えない場合→NULLとか判断する前にsegmentationfaultが出てくる
    →結局 mallocで動的に与えれば良かった
*/
int main(int argc, char const *argv[])
{
    char *a=" ";
    scanf("%s",a);
    if(a == NULL){
        printf("a は nullです\n");
        return 1;
    }
    printf("%s\n",a);
    return 0;
}
