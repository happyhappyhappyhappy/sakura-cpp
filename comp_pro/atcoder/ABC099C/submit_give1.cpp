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
    return false;
}

const ll INFDATA=1LL<<61;
const ll MAXBOX=101000;
vector<ll> DP(MAXBOX);

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    cout << fixed << setprecision(10);
    for(ll j=0;j < MAXBOX; j++){
        DP[j] = INFDATA;
    }    
    DP[0] = 0;
}
ll solver(ll x){
    ll result = x;
// TODO:ここを埋めよう
    return result;
}


int main(void){
    initial();
    ll inputdata;
    cin >> inputdata;
    cout << solver(inputdata) << "\n";
    return 0;
}