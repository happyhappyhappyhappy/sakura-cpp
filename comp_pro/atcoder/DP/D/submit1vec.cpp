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
    else{
        return false;
    }
}

ll N;
ll W;
vector<ll> weight(110);
vector<ll> value(110);

vector<vector<ll>> dp(110,vector<ll>(100100,0));

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    cout << fixed << setprecision(10);    
}

int main(void){
    initial();
    cin >> N >> W;
    for(ll j=0;j<N;j=j+1){
        cin >> weight[j] >> value[j];
    } 
    for(ll j=0;j<N;j=j+1){
        for(ll sum_weight=0;sum_weight <= W;sum_weight=sum_weight+1){
            if(sum_weight >= weight[j]){
                changeMax(dp[j+1][sum_weight],
                dp[j][sum_weight-weight[j]]+value[j]);
            }
            changeMax(dp[j+1][sum_weight],dp[j][sum_weight]);
        }
    }
    cout << dp[N][W] << "\n";
    return 0;
}