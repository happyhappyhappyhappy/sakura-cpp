#include<thread>
#include<cstdio>
#include<cstdint>
#include<iostream>
using namespace std;

uint32_t count_;

void ThreadA(){
    for(int i=0;i<100000;i=i+1){
        count_ = count_ + 1;
    }
}

void ThreadB(){
    for(int i=0;i<100000;i=i+1){
        count_ = count_ + 1;
    }
}

int main(void){
    count_ = 0;
    thread th_a(ThreadA);
    thread th_b(ThreadB);

    th_a.join();
    th_b.join();

    printf("count_ : %d\n",count_);

}