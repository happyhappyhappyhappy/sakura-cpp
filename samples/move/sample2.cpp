#include<bits/stdc++.h>
#include<chrono>
#include<algorithm>
using namespace std;
using namespace std::chrono;
// cf https://cpprefjp.github.io/reference/chrono.html
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
// move メソッドを与える場合。右辺値宣言もあり
class large_class{
    private:
        char* ptr;
    public:
    large_class(){
        ptr = new char[10000];
    }
    // large_class(const large_class& r){
    //     ptr = new char[10000];
    //     copy(r.ptr,r+ptr+10000,ptr);
    // }
    large_class(large_class&& r){
        ptr = r.ptr;
        r.ptr = nullptr;
    }
    large_class& operator=(large_class&& r){
        delete[] ptr;
        ptr = r.ptr;
        r.ptr = nullptr;
        return *this;
    }
    ~large_class(){
        delete[] ptr;
    }
};
int main(void){
    system_clock::time_point start,end;
    double elaspd;
    large_class tmp{};
    large_class y{};
    start = system_clock::now();
    large_class x(move(tmp));
    y = move(x);
    end = system_clock::now();
    elaspd = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
    cout << "Time is : " << elaspd << " nano_s\n" << flush;
    return 0;
}

// コピーしているところだけを抜粋
// Time is : 8300 nano_s