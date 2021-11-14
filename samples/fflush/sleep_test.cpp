#include<iostream>
#include<thread>
#include<chrono>
using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

int main(void){
    cout << "開始\n" ;
    sleep_for(seconds(3));
    cout << "終了\n" ;
    return 0;
}
