#include<cstdint>
#include<iostream>
#include<mutex>
#include<thread>

using namespace std;

mutex mtx_; // 排他制御ミューテックス(mutex)
uint32_t count_;

void add_count(void){
    // count_を加算する前にmutexを取得する
    lock_guard<mutex> lock(mtx_);
    count_=count_+1;
}

void ThreadA(void){
    for(int j=0;j<100000;j++){
        cout << "ThreadA Plus" << "\n";
        add_count();
    }
}

void ThreadB(void){
    for(int j=0;j<100000;j++){
        cout << "ThreadB Plus" << "\n";
        add_count();
    }
}

int main(void){
    count_ = 0;
    thread th_a(ThreadA);
    thread th_b(ThreadB);
    th_a.join();
    th_b.join();

    cout << "count_ : " << count_ << "\n";
    return 0;
}
/** 実行結果
-----
ThreadA Plus
ThreadA Plus
ThreadA Plus
(中略)
ThreadA PlusThreadB Plus
ThreadB Plus
(中略)
ThreadB PlusThreadA Plus
(中略)
count_ : 200000
-----
一応`ThreadX Plus`には終わりに"\n"を付けているのだが所々くっついているところ
と、離れている所が存在する
**/