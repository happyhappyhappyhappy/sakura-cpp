#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

// 設定した数まで列挙して判定するプログラム

ll N=1000;

bool is_prime(ll X){
    if(X == 1)return false;
    for(ll j=2;j*j <= X; j++){
        if( X % j == 0)return false;
    }
    return true;
}


int main(void){

    for(ll j=2;j<N;j++){
        if(is_prime(j)){
            cout << j << " は素数です\n" << flush;
        }   
        else{
            cout << j << " は素数ではありません\n" << flush;
        }
    }
    return 0;
}