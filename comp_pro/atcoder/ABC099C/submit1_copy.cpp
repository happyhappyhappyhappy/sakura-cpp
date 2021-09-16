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

const ll INFDATA= 1LL<<61;
const ll INFBOX=101010;
const vector<ll> DP(INFBOX);

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);
    for(ll j=0;j < INFBOX; j++){
        DP[j] = INFDATA;
        DP[0] = 0;
    }    
}

ll f(ll totalValue){
    result = INFDATA;
    if(totalValue==0){
        return DP[0];
    }
    // coin 1
    changemin(result,f(totalValue-1)+1);
    // coin 6
    ll cv6;
    cv6 = 6;
    while(totalValue >= cv6) { // つまり totalValue < cv6になれば終わり
        changemin(result,f(totalValue-cv6)+1);
        cv6 = cv6 * 6;
    // coin9
    ll cv9;
    cv9 = 9;
    while(totalValue >= cv9){
        changemin(result,f(totalValue-cv6)+1);
        cv9 = cv9 * 9;
    }
    // 次はここから
    return result;
}

int main(void){
    initial();
    ll giveMoney;
    // cin >> giveMoney;
    giveMoney=100;
    cout << f(giveMoney) << "\n";
    return 0;
}