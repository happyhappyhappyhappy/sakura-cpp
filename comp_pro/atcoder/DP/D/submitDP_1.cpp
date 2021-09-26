#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

template<class XXX> inline bool changeMax(XXX& x,XXX y){
    if(x < y){
        x = y;
        return true;
    }
    return false;
}

// Global変数
ll N;
ll W;
ll G_GOODS=110;
ll AVAIVLE_LEFTOVER=100100;
vector<vector<ll>> DP(G_GOODS,vector<ll> AVAIVLE_LEFTOVER);

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    cout << fixed << setprecision(10);    
}

ll solver(ll GOODS_COUNT,ll GOODS_SUMWEIGHT){
    ll result=0;
    // DP初期値設定
    for (ll j = 0; j < G_GOODS; j++)
    {
        for(ll k=0; k < AVAIVLE_LEFTOVER;k++){
            DP[j][k]=0;
    }
    vector<ll> weight(G_GOODS,0);
    vector<ll> value(G_GOODS,0);
    for(ll j=0;j<GOODS_COUNT;j++){
        cin >> weight[j] >> value[j];
    }
    for(ll j=0;j<GOODS_COUNT;j=j+1){
        for(ll sum_weight=0;sum_weight <= GOODS_SUMWEIGHT;
        sum_weight=sum_weight+1){
            if(sum_weight - weight[j] > 0){
                changeMax(DP[j+1][sum_weight-weight[j]]+value[j]);
            }
            changeMax(DP[j+1][sum_weight],DP[j+1][sum_weight]);
        }
    }
    result = DP[GOODS_COUNT][GOODS_SUMWEIGHT];
    return result;
}

int main(void){

    initial();
    ll N;
    ll W;
    cin >> N >> W ;
    cout << solver(N,W) << "\n";
    return 0;
}