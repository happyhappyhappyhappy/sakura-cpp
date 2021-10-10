#include<thread>
#include<cstdio>
#include<cstdint>
// 銀行口座みたいに片方が追加、片方が利用としていった場合
// 同じ所であればこの計算は0になるはずであるが･･･
using namespace std;

uint32_t count_ ;

void ThreadA(void){
    for(int j=0;j<100000;j=j+1){
        count_ = count_ + 1;
    }
}

void ThreadB(void){
    for(int j=0;j<100000;j=j+1){
        count_ = count_ - 1;
    }
}

int main(void){
    count_ = 0;
    thread th_a(ThreadA);
    thread th_b(ThreadB);
    th_a.join();
    th_b.join();

    printf("現在の口座残高 count_: %d\n",count_);

    return 0;
}
/**
 [実行結果] 数例実行した
[kaede@cppkaede thread]$ ./a21.out                                 [2021/10/10| 5:31午後]
現在の口座残高 count_: -3050
[kaede@cppkaede thread]$ ./a21.out                                 [2021/10/10| 5:31午後]
現在の口座残高 count_: 0
[kaede@cppkaede thread]$ ./a21.out                                 [2021/10/10| 5:31午後]
現在の口座残高 count_: -22564
[kaede@cppkaede thread]$ ./a21.out                                 [2021/10/10| 5:31午後]
現在の口座残高 count_: -17964
[kaede@cppkaede thread]$ ./a21.out                                 [2021/10/10| 5:31午後]
現在の口座残高 count_: 7255
(補足) それぞれの加減算を10000にすると案外差がでない。
 **/