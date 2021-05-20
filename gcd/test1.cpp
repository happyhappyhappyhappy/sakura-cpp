#include<iostream>
using namespace std;
using ll=long long;

ll modpow(ll a,ll n,ll mod){
    ll res  = 1;
    while(n > 0){
        if(n & 1){
            res = (res * a) % mod; 
        }
        n >> 1;
    }
    return 1;
}
