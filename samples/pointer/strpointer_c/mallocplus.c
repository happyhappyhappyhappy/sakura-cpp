#include<stdio.h>
#include<stdlib.h>

/* #define BUF 65535 */
#define BUF 1
/*
宣言後に使って見た場合
1.ひとまず直接入れた場合→印字可能
2.scanfを中継した場合→印字が止まらない→scanfのフォーマットに改行文字を入れたらダメ
3.大きさを[yamanakakohji]の14+1個にした場合→ctrl+dで出た
4.BUFを15->65535に戻した場合
5.BUFを5に小さくした場合→OK
6.BUFを1にした場合
*/

int main(int argc, char const *argv[])
{
    char *a;
    a=(char *)malloc(BUF);
    scanf("%s",a);
    if (a == NULL)
    {
        printf("a is NULL.\n");
    }
    else{
        printf("%s\n",a);
    }
    free(a);
    if(a == NULL)
    {
        printf("a is NULL.\n");
    }
    else{
        printf("%s\n",a);
    }
    return 0;
}
