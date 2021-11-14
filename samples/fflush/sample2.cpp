#include<iostream>
#include<thread>
#include<chrono>
using namespace std;
using namespace std::chrono;
using namespace std::this_thread;
#define N 2000

int main(void){
    int j;
    for(j=0;j < N;j=j+1){
        cout << j << " ," << flush;
        sleep_for(milliseconds(5));
    }
    return 0;
}