#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

template<class XXX> inline bool changeMax(XXX& a,XXX b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

ll N;
ll W;

vector<vector<ll>> dp(100,vector<ll>(100100,0));
vector<ll> weight[110];
vector<ll> value[110];

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    cout << fixed << setprecision(10);    
}
int main(void){
    
    cin >> N >> W;
    for(ll j=0;j<N;j++){
        cin >> weight[j] >> value<j>;
        // TODO:次はここからDPの書き込みスタート
        // for(ll j)
    }

    return 0;
}