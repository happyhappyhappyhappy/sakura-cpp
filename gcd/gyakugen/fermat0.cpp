#include<iostream>
// フェルマーの小定理が正しいかどうか確認する
using std::cout; 
using std::endl;
// using std::pow;
using ll = long long;

ll ISPRIME=19;

ll fermatTheoremCheck(ll base,ll powNum){
    ll res = 1;
    ll a = base;
    while(powNum > 0){
        if(powNum & 1){
            res = (res * a) % ISPRIME; 
        }        
        a = (a * a) % ISPRIME;
        powNum = powNum >> 1;
    }
    return res;
}
int main(int argc, char const *argv[])
{
    ll answer;
    for(ll i = 2;i <= ISPRIME;i++){
        cout << i << "^" << (ISPRIME-1) << "MOD " << ISPRIME << " = " \
         << fermatTheoremCheck(i,ISPRIME-1) << endl;
    }    
    return 0;
}
