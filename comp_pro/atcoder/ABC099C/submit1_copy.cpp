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

// const ll N;
// const vector<ll> memo(101010);

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);    
}

ll f(ll totalValue){
    ll result = 0;

    return result;
}

int main(void){
    initial();
    ll giveMoney;
    cin >> giveMoney;
    cout << f(giveMoney) << "\n";
    return 0;
}