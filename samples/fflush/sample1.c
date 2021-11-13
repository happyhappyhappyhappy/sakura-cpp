#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>

#define N 2000

int main(void){
    struct timeval start;
    struct timeval end;
    int j;
    for(j = 0 ; j < N ; ++j){
        printf("%d ,",j);
        usleep(5000);
    }
    return 0;
}