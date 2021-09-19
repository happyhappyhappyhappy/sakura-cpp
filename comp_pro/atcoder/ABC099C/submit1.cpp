#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;


template<class XXX> inline bool changemin(XXX& x,XXX y){
    if(x > y){
        x = y;
        return true;
    }
    else{
        return false;
    }
}

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);    
}

int main(void){
    initial();
    const ll TABLESIZE=200000;
    const ll LIMITDATA=1LL<<61;
    ll DP[TABLESIZE];
    for(ll j=0;j<TABLESIZE;j=j+1){
        DP[j] = LIMITDATA;
    }
    
    cin >> giveMoney;

    return 0;
}