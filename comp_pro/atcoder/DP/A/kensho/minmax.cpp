#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

 /**
template <class XXX> inline bool chmin(XXX &a,XXX b){
    bool result=false;
    cout << "a: " << a << "\tb: " << b  << "\n";
    if(b < a){
        a = b;
        result = true;
    }
    return result;
**/
 
template<class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    
    int sampleA,sampleB;
    bool result;
    cout << "---- そのまま変わらない場合 ----\n";
    sampleA = 2;
    sampleB = 4;
    cout << "sampleA = " << sampleA << "\tsampleB = " 
    << sampleB<< "\n";
    result = chmin(sampleA,sampleB);
    cout << "↓ 更新実行後\t";
    if(result){cout << "変更あり\n";}else{cout << "変更無し\n";}
    cout << "sampleA = " << sampleA << "\tsampleB = " 
    << sampleB<< "\n";
    cout << "---- 変わる場合 ----\n";
    sampleA = 100;
    sampleB = 50; 
    cout << "sampleA = " << sampleA << "\tsampleB = " 
    << sampleB<< "\n";
    result = chmin(sampleA,sampleB);
    cout << "↓ 更新実行後\t";
    if(result){cout << "変更あり\n";}else{cout << "変更無し\n";}
    cout << "sampleA = " << sampleA << "\tsampleB = " 
    << sampleB<< "\n";
    return 0;
}
