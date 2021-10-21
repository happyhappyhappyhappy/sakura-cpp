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
map<ll,ll> prime_factor(ll D){
    map<ll,ll> result;
    for(ll j=2LL;j*j<=D;j=j+1){
        while(D%j == 0LL){
            result[j]=result[j]+1;
            D = D / j;
        }
    }
    if( D != 1LL){
        result[D] = 1LL;
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
        it++;
    }
    return 0;
}
