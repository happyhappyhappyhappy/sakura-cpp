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
vector<ll> weight(110);
vector<ll> value(110);

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    cout << fixed << setprecision(10);    
}
int main(void){
    
    cin >> N >> W;
    for(ll j=0;j<N;j++){
        cin >> weight[j] >> value[j];
    }
    for(ll j=0;j<N;j++){
        for(ll sum_weight=0;sum_weight<=W;sum_weight=sum_weight+1){
            if(W >= sum_weight){
                changeMax(dp[j+1][sum_weight],dp[j][W-sum_weight]+value[j]);
            }
            changeMax(dp[j+1][sum_weight],dp[j][sum_weight]);
        }
    }
    cout << dp[N][W] << "\n";
    return 0;
}