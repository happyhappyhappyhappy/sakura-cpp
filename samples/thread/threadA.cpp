#include<thread>
#include<cstdio>
#include<cstdint>
#include<iostream>

using namespace std;

uint32_t end_flag_;
uint32_t msg_;

void ThreadA(void){
    int32_t input=0;
    while(end_flag_){
        cout << "数字を入力してください\n";
        cout << "0...スレッドBにメッセージを送信します\n";
        cout << "1...プロセスを終了します\n";
        scanf("%d",&input);
        switch(input){
            case 0:
                msg_ = 1;
                break;
            case 1:
                end_flag_ = 0;
                break;
            default :
                cout << "0か1を入力してください\n";
        }
    }
    cout << "スレッドA終了\n";
}

void ThreadB(void){
    while(end_flag_){
        if(msg_)
        {
            cout << "スレッドAからメッセージを受け取りました\n";
            msg_ = 0;
        }
    }
    cout << "スレッドB終了\n";
}

int main(void){
    msg_ = 0;
    end_flag_ = 1;

    thread th_a(ThreadA);
    thread th_b(ThreadB);

    th_a.join();
    th_b.join();

    return 0;
}