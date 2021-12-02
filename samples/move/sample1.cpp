#include<bits/stdc++.h>
#include<chrono>
#include<algorithm>
using namespace std;
using namespace std::chrono;
// cf https://cpprefjp.github.io/reference/chrono.html
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
// Key: move function
// move関数を使って見る
// 元のサンプル
class large_class{
    private:
        char* ptr;
    public:
    large_class(){
        ptr = new char[10000];
    }
    large_class(const large_class& r){
        ptr = new char[10000];
        copy(r.ptr,r.ptr+10000,ptr);
    }
    ~large_class(){
        delete[] ptr;
    }
};

int main(void){
    system_clock::time_point start,end;
    double elaspd;
    start = system_clock::now();
    large_class x{};
    large_class y(x);
    end = system_clock::now();
    elaspd = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    cout << "Time is : " << elaspd << " nano_s\n" << flush; 
    return 0;
}
/**
 Time is : 20500 nano_s
**/