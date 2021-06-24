#include<stdio.h>
#include<stdlib.h>
/*
[検証] ポインタ変数`*a`を作って、aに文字列を入れた例
*/
int main(int argc, char const *argv[])
{
    char *a;
/*
    余計な出力分は削除
    printf("InputString : ");
*/    
    scanf("%s\n",a);
    if (a == NULL)
    {
        printf("NULL POINTER!!\n");
    }
    else
    {
        printf("Your Input : %s .\n",a);
    }
    return 0;
}
/*
何も宣言しないと(null)になる
*/