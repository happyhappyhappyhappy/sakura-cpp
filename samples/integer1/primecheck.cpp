#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

// 与えられた数に対して素数かどうか判定するプログラム

bool is_prime(ll X){
    if(X == 1)return false;
    for(ll j=2;j*j <= X; j++){
        if( X % j == 0)return false;
    }
    return true;
}


int main(void){
    ll N;
    cin >> N;
    if(is_prime(N)){
        cout << N << " は素数です\n" << flush;
    }
    else{
        cout << N << " は素数ではありません\n" << flush;
    }
}