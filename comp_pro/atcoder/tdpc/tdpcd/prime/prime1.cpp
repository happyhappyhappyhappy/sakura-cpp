#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);    
}
int N;
ll D;
map<ll,ll> prime_factor(ll n){
    // TODO: これのミスでやらかしたところを再度コンパイルして実行
    map<ll,ll> result;
    for(ll j=2LL;j*j<=n;j=j+1){
        while(n%j == 0LL){
            ++result[j];
            n /= j;
        }
    }
    if( n != 1LL){
        result[n] = 1LL;
    }
    return result;
}

int main(void){
    initial();
    cin >> N >> D;
    map<ll,ll> primeMap;
    primeMap = prime_factor(D);
    map<ll,ll>::iterator it;
    it = primeMap.begin();
    while(it != primeMap.end()){
        cout << it->first << " :: " << it->second << "\n";
    }
    return 0;
}