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

ll dp[100][100100];
ll weight[110];
ll value[110];

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(ll j=0;j<100;j=j+1){
        for(ll k=0;k<100100;k=k+1){
            dp[j][k] = 0;
        }
    }
//    cout << fixed << setprecision(10);    
}
int main(void){
    initial();
    cin >> N >> W;
    for(ll j=0;j<N;j++){
        cin >> weight[j] >> value[j];
    }
    for(ll j=0;j<N;j++){
        for(ll sum_weight=0;sum_weight<=W;sum_weight=sum_weight+1){
            if( sum_weight - weight[j] >= 0){
                changeMax(dp[j+1][sum_weight],dp[j][sum_weight-weight[j]]+value[j]);
            }
            changeMax(dp[j+1][sum_weight],dp[j][sum_weight]);
        }
    }
    cout << dp[N][W] << "\n";
    return 0;
}